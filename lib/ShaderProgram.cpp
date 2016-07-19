#include "ShaderProgram.h"

// ========== constructors and destructors ========== 

ShaderProgram::ShaderProgram() {
	linked = false;
	return;
} // ShaderProgram

ShaderProgram::ShaderProgram( const std::string &shaderNameIn ) {
	linked = false;
	linked = buildShaderProgram( shaderNameIn );
	return;
}

// ========== API functions ========== 

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

void ShaderProgram::setActive() {
	glUseProgram( shaderProgramID );
} // setActive

