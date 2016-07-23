#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <vector>

#include "SpriteHelper.h"

// NOTE: All frames of a spritesheet must have the same dimensions!

struct SpriteData {
	std::string filepath;
	unsigned int frameWidth, frameHeight;
	std::vector < unsigned int > numFrames;
};

/*
 * This class includes API-callable members.
 * Therefore, public members must abstract away library-related details.
 */

class Sprite {

#ifdef ENGINE_DEBUG
	friend class EngineTest;
#endif

private:

	SpriteHelper* spriteHelper;

	std::vector < unsigned int > numFrames;
	unsigned int frameWidth, frameHeight;
	unsigned int numAnimations;

	std::vector < std::vector < GLuint > > vertexArrays;
	bool loaded;

	// ========== disabled functions ==========

	Sprite() = delete;

	// Sprites should not be copied (for efficiency purposes)
	// (This is because the same sprite can be drawn multiple times in multiple locations)
	Sprite( const Sprite& src ) = delete;
	Sprite& operator=( const Sprite& src ) = delete;

	// move constructors
	// again, deleted for efficiency purposes
	Sprite( Sprite&& src ) = delete;
	Sprite& operator=( const Sprite&& src ) = delete;

	// ========== private member functions ==========

	// create a vetex array object for each animation frame in the spritesheet
	void generateVertices();

public:

	// ========== constructors and destructors ==========

	Sprite( const SpriteData &spriteData );
	~Sprite();

	// ========== get and set member variables ==========

	// TODO: other getting/setting functions
	unsigned int getFrameWidth() const;
	unsigned int getFrameHeight() const;
	
	// note: these functions are not const because they load the sprite if it
	// has not been loaded
	GLuint getTextureID();
	GLuint getFrameID( const int animation, const int frame );

	// ========== API functions ==========

	// Load spritesheet and call generateVertices to prepare frames for rendering
	bool load( const std::string &filepath = "" );

};

#endif

