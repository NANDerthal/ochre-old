#include "Sprite.h"

// ========== constructors and destructors ==========

Sprite::Sprite( const SpriteData &spriteData ) {
	spriteHelper = new SpriteHelper( spriteData.filepath );
	frameWidth = spriteData.frameWidth;
	frameHeight = spriteData.frameHeight;
	numFrames = spriteData.numFrames;

	return;
} // Sprite

Sprite::~Sprite() {
	delete spriteHelper;
	spriteHelper = nullptr;

	for ( int i = 0; i < vertexArrays.size(); ++i ) {
		for (int j = 0; j < vertexArrays[i].size(); ++j ) {
			glDeleteVertexArrays( 1, &(vertexArrays[i][j]) );
		}
	}

	return;
} // ~Sprite

// ========== private members ==========

void Sprite::generateVertices() {
	GLfloat x, y, w, h;
	w = (GLfloat)frameWidth / (GLfloat)spriteHelper->getWidth();
	h = (GLfloat)frameHeight / (GLfloat)spriteHelper->getHeight();

	for ( int i = 0; i < numAnimations; ++i ) {
		std::vector < GLuint > animRow( numFrames[i] );
		vertexArrays.push_back( animRow );
		for ( int j = 0; j < numFrames[i]; ++j ) {
			x = j*w;
			y = i*h;

			GLint VAO = spriteHelper->generateVertexArray( frameWidth, frameHeight, x, y, w, h );

			vertexArrays[i][j] = VAO;
		}
	}

	return;
} // generateVertices

// ========== API functions ==========

bool Sprite::load( const std::string &filepath ) {
	if ( filepath != "" ) {
		spriteHelper->setFilepath( filepath );
	}

	if ( !spriteHelper->load() ) {
		printf( "Spritesheet failed to load!" );
		return false;
	}

	if ( spriteHelper->getHeight() % frameHeight ) {
		printf( "Invalid sprite paramaters! Frame height does not divide sheet height." );
		return false;
	}

	numAnimations = spriteHelper->getHeight() / frameHeight;
	vertexArrays.reserve( numAnimations );

	// Generate OpenGL Vertices
	generateVertices();

	return true;
} // load

