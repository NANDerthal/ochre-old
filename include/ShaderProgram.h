#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <string>

#ifdef DEBUG
	#include "Engine.h"
#endif
#include "Shader.h"

/*
 * This class includes API-callable members.
 * Therefore, public members must abstract away library-related details.
 */

class ShaderProgram {

#ifdef DEBUG
	friend class EngineTest;
#endif

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

