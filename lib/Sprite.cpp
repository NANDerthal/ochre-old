#include "Sprite.h"

// ========== constructors and destructors ==========

Sprite::Sprite( const SpriteData &spriteData ) {
	spriteHelper = new SpriteHelper( spriteData.filepath );
	frameWidth = spriteData.frameWidth;
	frameHeight = spriteData.frameHeight;
	numFrames = spriteData.numFrames;

	loaded = false;

	return;
} // Sprite

Sprite::~Sprite() {
	delete spriteHelper;
	spriteHelper = nullptr;

	for ( unsigned int i = 0; i < vertexArrays.size(); ++i ) {
		for ( unsigned int j = 0; j < vertexArrays[i].size(); ++j ) {
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

	for ( unsigned int i = 0; i < numAnimations; ++i ) {
		std::vector < GLuint > animRow( numFrames[i] );
		vertexArrays.push_back( animRow );
		for ( unsigned int j = 0; j < numFrames[i]; ++j ) {
			x = j*w;
			y = i*h;

			GLint VAO = spriteHelper->generateVertexArray( frameWidth, frameHeight, x, y, w, h );

			vertexArrays[i][j] = VAO;
		}
	}

	return;
} // generateVertices

// ========== get and set member variables ==========

unsigned int Sprite::getFrameWidth() const {
	return frameWidth;
} // getFrameWidth

unsigned int Sprite::getFrameHeight() const {
	return frameHeight;
} // getFrameHeight

GLuint Sprite::getTextureID() {
	if ( !loaded ) {
		loaded = load();
		if ( !loaded ) {
			printf( "Spritesheet failed to load! (Called load() from getTextureID().)\n" );
		}
	}
	return spriteHelper->getTextureID();
} // getTextureID

GLuint Sprite::getFrameID( const int animation, const int frame ) {
	if ( !loaded ) {
		loaded = load();
		if ( !loaded ) {
			printf( "Spritesheet failed to load! (Called load() from getFrameID().)\n" );
		}
	}
	return vertexArrays[ animation ][ frame ];
} // getFrameID

// ========== API functions ==========

bool Sprite::load( const std::string &filepath ) {
	if ( ( loaded ) && ( filepath == "" ) ) {
		return true;
	}

	if ( filepath != "" ) {
		spriteHelper->setFilepath( filepath );
	}

	if ( !spriteHelper->load() ) {
		printf( "Spritesheet failed to load!\n" );
		return false;
	}

	if ( spriteHelper->getHeight() % frameHeight ) {
		printf( "Invalid sprite paramaters! Frame height does not divide sheet height.\n" );
		return false;
	}

	numAnimations = spriteHelper->getHeight() / frameHeight;
	vertexArrays.reserve( numAnimations );

	// Generate OpenGL Vertices
	generateVertices();

	return true;
} // load

