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

	// ========== library-dependent functions ==========

	bool buildShaderProgram( const std::string &shaderNameIn = "" );

	// ===== OpenGL state setting =====
	void setActive() const;
	void setInactive() const;

	// ===== Program variable setting =====

	// set textures to render
	void setUniform( const GLuint textureID ) const;

	// set transformation matrices
	void setUniform( const GLfloat* matrixPtr ) const;
	

};

#endif

