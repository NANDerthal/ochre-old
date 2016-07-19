#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <string>

#include "Shader.h"

/*
 * This class includes API-callable members.
 * Therefore, public members must abstract away library-related details.
 */

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

