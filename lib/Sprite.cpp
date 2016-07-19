#include "Sprite.h"

Sprite::Sprite( const SpriteData &spriteData ) {
	helper = new SpriteHelper( spriteData.filepath );
	frameWidth = spriteData.frameWidth;
	frameHeight = spriteData.frameHeight;
	numFrames = spriteData.numFrames;

	return;
} // Sprite

Sprite::~Sprite() {
	delete helper;
	helper = nullptr;

	return;
} // ~Sprite

void Sprite::generateVertices() {
	GLfloat x, y, w, h;
	w = (GLfloat)frameWidth / (GLfloat)helper->getWidth();
	h = (GLfloat)frameHeight / (GLfloat)helper->getHeight();

	for ( int i = 0; i < numAnimations; ++i ) {
		std::vector < GLint > animRow( numFrames[i] );
		vertexArrays.push_back( animRow );
		for ( int j = 0; j < numFrames[i]; ++j ) {
			x = j*w;
			y = i*h;
			
			GLfloat frame[] = {
				// frame xyz   		    texture coordinates
				1.0f, 1.0f, 0.0f, 		x+w, 	y+h,
				1.0f, 0.0f, 0.0f,		x+w,	y,
				0.0f, 0.0f, 0.0f,		x,		y,
				0.0f, 1.0f, 0.0f, 		x,		y+h
			};

			GLint VAO = helper->generateVertexArray( frame );

			vertexArrays[i][j] = VAO;
		}
	}

	return;
} // generateVertices

bool Sprite::load( std::string filepath ) {
	if ( filepath != "" ) {
		helper->setFilepath( filepath );
	}

	if ( !helper->load() ) {
		printf( "Spritesheet failed to load!" );
		return false;
	}

	if ( helper->getHeight() % frameHeight ) {
		printf( "Invalid sprite paramaters! Frame height does not divide sheet height." );
		return false;
	}

	numAnimations = helper->getHeight() / frameHeight;

	// Generate OpenGL Vertices
	generateVertices();

	return true;
} // load

