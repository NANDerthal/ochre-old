#include "SpriteHelper.h"

#ifdef USING_WINDOWS
	#include <glew.h>
	#include <SOIL.h>
#else
	#include <GL/glew.h>
	#include <SOIL/SOIL.h>
#endif

// ========== constructors and destructors ==========

SpriteHelper::SpriteHelper( const std::string filepathIn ) {
	filepath = filepathIn;
	loaded = false;
	return;
} // SpriteHelper

SpriteHelper::~SpriteHelper() {
	glDeleteTextures( 1, &textureID );
	return;
} // ~SpriteHelper

// ========== getters and setters ==========

int SpriteHelper::getWidth() const {
	return textureWidth;
} // getWidth

int SpriteHelper::getHeight() const {
	return textureHeight;
} // getHeight

void SpriteHelper::setFilepath( const std::string filepathIn ) {
	filepath = filepathIn;
	loaded = false;
	return;
} // setFilepath

// ========== loading ==========

bool SpriteHelper::load( const std::string filepathIn ) {
	if ( loaded ) {
		glDeleteTextures( 1, &textureID );
		loaded = false;
	}

	if ( filepathIn != "" ) {
		filepath = filepathIn;
	}

	// load image from file
	unsigned char* image = SOIL_load_image( filepathIn.c_str(), &textureWidth, &textureHeight, 0, SOIL_LOAD_RGB );
	if ( image == NULL ) {
		printf( "Image %s could not be loaded! SOIL error: %s\n", filepath, SOIL_last_result() );
		return false;
	}

	// create OpenGL texture from image
	glGenTextures( 1, &textureID );
	glBindTexture( GL_TEXTURE_2D, textureID );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image );
	glGenerateMipmap( GL_TEXTURE_2D );
	GLenum error = glGetError();
	if ( error ) {
		printf( "Image %s could not be bound as a texture! OpenGL error: %d\n", filepath, error );
		return false;
	}

	// free image (no longer needed)
	SOIL_free_image_data( image );

	loaded = true;

	return true;
} // load

GLint SpriteHelper::generateVertexArray( const GLfloat* frame ) {
	GLuint indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	GLuint EBO;
	glGenBuffers( 1, &EBO );

	GLuint VBO;
	glGenBuffers( 1, &VBO );

	GLuint VAO;
	glGenVertexArrays( 1, &VAO );
	glBindVertexArray( VAO );
		glBindBuffer( GL_ARRAY_BUFFER, VBO );
		glBufferData( GL_ARRAY_BUFFER, sizeof( frame ), frame, GL_STATIC_DRAW );

		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO );
		glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( indices ), indices, GL_STATIC_DRAW );

		// Position attributes
		glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof( GLfloat ), (GLvoid*)0 );
		glEnableVertexAttribArray( 0 );

		// Texture coordinate attributes
		glVertexAttribPointer( 1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof( GLfloat ), (GLvoid*)(3 * sizeof( GLfloat )) );
		glEnableVertexAttribArray( 1 );
	glBindVertexArray( NULL );

	return VAO;
} // generateBuffers

