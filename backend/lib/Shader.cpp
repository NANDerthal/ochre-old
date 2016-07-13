#include "Shader.h"

#include <fstream>

Shader::Shader() {
	filepath = "";
	compiled = false;
	return;
} // Shader()

Shader::Shader( std::string filepathIn, GLenum shaderTypeIn ) {
	setFilepath( filepathIn );
	setShaderType( shaderTypeIn );
	return;
} // Shader( filepathIn, shaderTypeIn )

Shader::~Shader() {
	if ( compiled ) {
		glDeleteShader( shaderID );
	}
	
	return;
} // ~Shader

// ========== getters and setters ==========

GLuint Shader::getShaderID() {
	if ( !compiled ) {
		compiled = createShader( filepath, shaderType );
		if ( !compiled ) {
			exit(1);
		}
	}
	
	return shaderID;
} // getShaderID

void Shader::setFilepath( std::string filepathIn ) {
	filepath = filepathIn;
	compiled = false;
	return;
} // setFilepath

void Shader::setShaderType( GLenum shaderTypeIn ) {
	shaderType = shaderTypeIn;
	compiled = false;
	return;
} // setShaderType

// ========== compilation ==========

bool Shader::createShader( std::string filepathIn, GLenum shaderTypeIn ) {
	if ( compiled ) {
		glDeleteShader( shaderID );
		compiled = false;
	}
	
	filepath = filepathIn;
	shaderType = shaderTypeIn;
	
	std::ifstream shaderFile;
	shaderFile.open( filepath.c_str() );
	
	if ( !shaderFile.is_open() ) {
		printf( "Failed to open shader file %s!", filepath );
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

