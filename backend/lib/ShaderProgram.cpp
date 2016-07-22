#include "ShaderProgram.h"

// ========== constructors and destructors ========== 

ShaderProgram::ShaderProgram() {
	linked = false;
	return;
} // ShaderProgram()

ShaderProgram::ShaderProgram( const std::string &shaderNameIn ) {
	linked = false;
	linked = buildShaderProgram( shaderNameIn );
	return;
} // ShaderProgram( shaderNameIn )

ShaderProgram::~ShaderProgram() {
	setInactive();
	glDeleteProgram( shaderProgramID );
	return;
} // ~ShaderProgram

// ========== library-dependent functions ========== 

bool ShaderProgram::buildShaderProgram( const std::string &shaderNameIn ) {

	// ===== Check if shader program already exists =====
	
	if ( ( shaderNameIn != "" ) && (shaderNameIn != shaderName) ) {
		shaderName = shaderNameIn;
		linked = false;
	}
	
	if ( linked ) {
		return true;
	}

	// ===== Make shader program if it does not exist =====
	
	std::string vertexFilepath = "backend/shaders/" + shaderName + ".vert";
	std::string fragmentFilepath = "backend/shaders/" + shaderName + ".frag";

	// == get shaders ==
	Shader vertex( vertexFilepath, GL_VERTEX_SHADER );
	Shader fragment( fragmentFilepath, GL_FRAGMENT_SHADER );

	// == create shader program ==
	shaderProgramID = glCreateProgram();
	
	glAttachShader( shaderProgramID, vertex.getShaderID() );
	glAttachShader( shaderProgramID, fragment.getShaderID() );
	glLinkProgram( shaderProgramID );
	
	GLint success;
	glGetProgramiv( shaderProgramID, GL_LINK_STATUS, &success );
	if ( !success ) {
	    GLchar infoLog[512];
	    glGetProgramInfoLog( shaderProgramID, 512, NULL, infoLog );
	    printf( "Failed to create shader program! OpenGL error: %s\n", infoLog );
		return false;
	}
	
	glDeleteShader( vertex.getShaderID() );
	glDeleteShader( fragment.getShaderID() );
	
	linked = true;
	
	return true;
} // buildShaderProgramID

// ===== OpenGL state setting =====

void ShaderProgram::setActive() const {
	glUseProgram( shaderProgramID );
	return;
} // setActive

void ShaderProgram::setInactive() const {
	// 0 is used in OpenGL as the default unused ID
	glUseProgram( 0 );
	return;
} // setInactive

// ===== Program variable setting =====

void ShaderProgram::setUniform( const GLuint textureID ) const {
	glActiveTexture( GL_TEXTURE0 );
	glBindTexture( GL_TEXTURE_2D, textureID );

	GLuint textureLocation = glGetUniformLocation(shaderProgramID, "ourTexture" );
	glUniform1i( textureLocation, 0 );

	return;
} // setUniform( textureID )

void ShaderProgram::setUniform( const GLfloat* matrixPtr ) const {
	GLuint transformationsLoc = glGetUniformLocation( shaderProgramID, "transformations" );
	glUniformMatrix4fv( transformationsLoc, 1, GL_FALSE, matrixPtr );

	return;
} // setUniform( matrixPtr )

