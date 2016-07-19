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

	// ========== get and set member variables ==========

	int getWidth() const;
	int getHeight() const;
	GLuint getTextureID() const;

	void setFilepath( const std::string filepathIn );

	// ========== library-dependent functions ==========

	GLint generateVertexArray( const GLfloat offsetX, const GLfloat offsetY,
							   const GLfloat rectWidth, const GLfloat rectHeight );

	// load image from file into OpenGL texture
	bool load( const std::string filepathIn = "" );

	// set texture stored by current object to be the active OpenGL texture
	void setActive() const;

};

#endif

