#include "ShaderProgram.h"

// ========== constructors and destructors ========== 

ShaderProgram::ShaderProgram() {
	linked = false;
} // ShaderProgram

// ========== API functions ========== 

bool ShaderProgram::buildShaderProgram( const std::string shaderName ) {

	std::string vertexFilepath = "backend/shaders/" + shaderName + ".vert";
	std::string fragmentFilepath = "backend/shaders/" + shaderName + ".frag";

	// ===== get shaders =====
	Shader vertex( vertexFilepath, GL_VERTEX_SHADER );
	Shader fragment( fragmentFilepath, GL_FRAGMENT_SHADER );

	// ===== create shader program =====
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
	
	linked = true;
	
	return true;
} // buildShaderProgramID

void ShaderProgram::setActive() {
	glUseProgram( shaderProgramID );
} // setActive

