#include "Shader.h"

#include <fstream>

// ========== constructors and destructors ==========

Shader::Shader( const std::string filepathIn, const GLenum shaderTypeIn ) {
	setFilepath( filepathIn );
	setShaderType( shaderTypeIn );
	compiled = false;
	return;
} // Shader

Shader::~Shader() {
	if ( compiled ) {
		glDeleteShader( shaderID );
	}
	
	return;
} // ~Shader

// ========== get and set member variables ==========

GLuint Shader::getShaderID() {
	if ( !compiled ) {
		compiled = createShader();
		if ( !compiled ) {
			printf( "Error compiling shader!" );
		}
	}
	
	return shaderID;
} // getShaderID

void Shader::setFilepath( const std::string filepathIn ) {
	filepath = filepathIn;
	compiled = false;
	return;
} // setFilepath

void Shader::setShaderType( const GLenum shaderTypeIn ) {
	shaderType = shaderTypeIn;
	compiled = false;
	return;
} // setShaderType

// ========== compilation ==========

bool Shader::createShader( const std::string filepathIn, const GLenum shaderTypeIn ) {
	if ( compiled ) {
		glDeleteShader( shaderID );
		compiled = false;
	}
	
	if ( filepathIn != "" ) {
		filepath = filepathIn;
		shaderType = shaderTypeIn;
	}
	
	std::ifstream shaderFile;
	shaderFile.open( filepath.c_str() );
	
	if ( !shaderFile.is_open() ) {
		printf( "Failed to open shader file %s!", filepath.c_str() );
		return false;
	}
	
	std::string tmp, shaderSource;
	
	while ( getline(shaderFile,tmp) ) {
		shaderSource += tmp;
		shaderSource += '\n';
	}
	
	shaderFile.close();
	
	const char *sfCStr = shaderSource.c_str();
	const int sfCStrLength = shaderSource.length();
	
	// create and compile shader
	shaderID = glCreateShader(shaderType);
	glShaderSource( shaderID, 1, &sfCStr, &sfCStrLength );
	glCompileShader( shaderID );
	
	// check errors
	GLint success;
	glGetShaderiv( shaderID, GL_COMPILE_STATUS, &success );
	if ( !success ) {
		GLchar infoLog[512];
		glGetShaderInfoLog( shaderID, 512, NULL, infoLog );
		printf( "Failed to compile shader! OpenGL error: %s\n", infoLog );
		return false;
	}
	
	compiled = true;
	
	return true;
} // createShader

