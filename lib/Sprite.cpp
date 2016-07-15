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

	return true;
} // load

