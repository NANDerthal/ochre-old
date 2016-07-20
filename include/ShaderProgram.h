#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <string>

#ifdef ENGINE_DEBUG
	#include "Engine.h"
#endif
#include "Shader.h"

/*
 * This class includes API-callable members.
 * Therefore, public members must abstract away library-related details.
 */

class ShaderProgram {

#ifdef ENGINE_DEBUG
	friend class EngineTest;
#endif

private:
	
	GLuint shaderProgramID;
	std::string shaderName;
	bool linked;

public:

	// ========== constructors and destructors ==========
	
	ShaderProgram();
	ShaderProgram( const std::string &shaderNameIn );

	~ShaderProgram();

	// ========== API functions ==========

	bool buildShaderProgram( const std::string &shaderNameIn = "" );
	void setActive();
	void setInactive();

};

#endif

