#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <string>

#include "Shader.h"

class ShaderProgram {

private:
	
	GLuint shaderProgramID;
	bool linked;

public:

	// ========== constructor ==========
	
	ShaderProgram();

	// ========== API functions ==========

	bool buildShaderProgram( const std::string shaderName );
	void setActive();

};

#endif

