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
	std::string shaderName;
	bool linked;

public:

	// ========== constructor ==========
	
	ShaderProgram();
	ShaderProgram( const std::string &shaderNameIn );

	// ========== API functions ==========

	bool buildShaderProgram( const std::string &shaderNameIn = "" );
	void setActive();

};

#endif

