#ifndef SHADER_H
#define SHADER_H

#include <string>

#ifdef USING_WINDOWS
	#include <glew.h>
#else
	#include <GL/glew.h>
#endif

class Shader {

private:
	
	GLuint shaderID;
	std::string filepath;
	GLenum shaderType;
	bool compiled;

public:

	// ========== constructors and destructors ==========
	
	Shader( const std::string filepathIn = "", const GLenum shaderTypeIn =- NULL );
	~Shader();

	// ========== getters and setters ==========
	
	// NOTE: compiles shader with createShader if not compiled yet
	GLuint getShaderID();
	
	void setFilepath( const std::string filepathIn );
	void setShaderType ( const GLenum shaderTypeIn );
	
	// ========== compilation ==========
	
	// returns true if compiled successfully, false if compilation failed
	bool createShader( const std::string filepathIn, const GLenum shaderTypeIn );

};

#endif

