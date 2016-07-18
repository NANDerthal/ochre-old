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
	int x, y, w, h;
	w = frameWidth / helper->getWidth();
	h = frameHeight / helper->getHeight();

	for ( int i = 0; i < numAnimations; ++i ) {
		std::vector < GLint > animRow( numFrames[i] );
		vertexArrays.push_back( animRow );
		for ( int j = 0; j < numFrames[i]; ++j ) {
			x = j*w;
			y = i*h;
			GLfloat frame[] = {
				// frame xyz     texture coordinates
				0, 0, 0,		x,		y+h,
				1, 0, 0,		x+w,	y+h,
				1, 1, 0, 		x+w, 	y,
				0, 1, 0, 		x,		y
		   	};

			GLint VAO = helper->generateVertexArray( frame );

			vertexArrays[i].push_back( VAO );
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

	// TODO: Generate OpenGL Vertices
	generateVertices();

	return true;
} // load

