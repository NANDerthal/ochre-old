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

// ========== get and set member variables ==========

int SpriteHelper::getWidth() const {
	return textureWidth;
} // getWidth

int SpriteHelper::getHeight() const {
	return textureHeight;
} // getHeight

GLuint SpriteHelper::getTextureID() const {
	return textureID;
}

void SpriteHelper::setFilepath( const std::string filepathIn ) {
	filepath = filepathIn;
	loaded = false;
	return;
} // setFilepath

// ========== library-dependent functions ==========

GLint SpriteHelper::generateVertexArray( const GLfloat offsetX, const GLfloat offsetY,
										 const GLfloat rectWidth, const GLfloat rectHeight ) {
	GLfloat frame[] = {
		// frame xyz   		    texture coordinates
		1.0f, 1.0f, 0.0f, 		offsetX + rectWidth, 	offsetY,
		1.0f, 0.0f, 0.0f,		offsetX + rectWidth,	offsetY + rectHeight,
		0.0f, 0.0f, 0.0f,		offsetX,				offsetY + rectHeight,
		0.0f, 1.0f, 0.0f, 		offsetX,				offsetY
	};

	static const GLuint indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	// Vertex buffer object (hold frame vertices)
	GLuint VBO;
	glGenBuffers( 1, &VBO );

	// Element buffer object (generate multiple triangles from given frame vertices)
	GLuint EBO;
	glGenBuffers( 1, &EBO );

	// Vertex array object (put together info from VBO and EBO so shaders can render them)
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
} // generateVertexArray

bool SpriteHelper::load( const std::string filepathIn ) {
	// ===== Check if sprite was already loaded =====

	if ( ( filepathIn != "" ) && ( filepathIn != filepath ) ) {
		filepath = filepathIn;
		if ( loaded ) {
			glDeleteTextures( 1, &textureID );
		}
		loaded = false;
	}

	if ( loaded ) {
		return true;
	}

	// ===== Load sprite if not already loaded =====

	// load image from file
	unsigned char* image = SOIL_load_image( filepath.c_str(), &textureWidth, &textureHeight, 0, SOIL_LOAD_RGBA );
	if ( image == NULL ) {
		printf( "Image %s could not be loaded! SOIL error: %s\n", filepath.c_str(), SOIL_last_result() );
		return false;
	}

	// create OpenGL texture from image
	glGenTextures( 1, &textureID );
	glBindTexture( GL_TEXTURE_2D, textureID );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, textureWidth, textureHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
	glGenerateMipmap( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, NULL );
	GLenum error = glGetError();
	if ( error ) {
		printf( "Image %s could not be bound as a texture! OpenGL error: %d\n", filepath.c_str(), error );
		return false;
	}

	// free image (no longer needed)
	SOIL_free_image_data( image );

	loaded = true;

	return true;
} // load

void SpriteHelper::setActive() const {
	glBindTexture( GL_TEXTURE_2D, textureID );
	return;
} // setActive

