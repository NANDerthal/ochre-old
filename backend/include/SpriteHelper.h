#ifndef SPRITE_HELPER_H
#define SPRITE_HELPER_H

#include <string>

#ifdef USING_WINDOWS
	#include <glew.h>
#else
	#include <GL/glew.h>
#endif

class SpriteHelper {

private:

	std::string filepath;
	GLuint textureID;
	int textureWidth, textureHeight;
	bool loaded;

public:

	// ========== constructors and destructors ==========

	SpriteHelper( const std::string filepathIn = "" );
	~SpriteHelper();

	// ========== getters and setters ==========

	int getWidth() const;
	int getHeight() const;

	void setActive();
	void setFilepath( const std::string filepathIn );

	// ========== loading ==========

	bool load( const std::string filepathIn = "" );
	GLint generateVertexArray( const GLfloat* frame );
};

#endif

