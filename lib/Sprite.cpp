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

	return;
} // ~Sprite

// ========== private members ==========

void Sprite::generateVertices() {
	GLfloat x, y, w, h;
	w = (GLfloat)frameWidth / (GLfloat)spriteHelper->getWidth();
	h = (GLfloat)frameHeight / (GLfloat)spriteHelper->getHeight();

	for ( int i = 0; i < numAnimations; ++i ) {
		std::vector < GLint > animRow( numFrames[i] );
		vertexArrays.push_back( animRow );
		for ( int j = 0; j < numFrames[i]; ++j ) {
			x = j*w;
			y = i*h;

			GLint VAO = spriteHelper->generateVertexArray( x, y, w, h );

			vertexArrays[i][j] = VAO;
		}
	}

	return;
} // generateVertices

// ========== API functions ==========

bool Sprite::load( std::string filepath ) {
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

	// Generate OpenGL Vertices
	generateVertices();

	return true;
} // load

