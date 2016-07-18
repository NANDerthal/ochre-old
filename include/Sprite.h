#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <vector>

#include "SpriteHelper.h"

struct SpriteData {
	std::string filepath;
	int frameWidth, frameHeight;
	std::vector < int > numFrames;
};

class Sprite {

private:

	SpriteHelper* helper;

	std::vector < int > numFrames;
	int frameWidth, frameHeight;
	int numAnimations;

	std::vector < std::vector < GLint > > vertexArrays;
	GLuint indices[];
	GLuint EBO, VBO;

	void generateVertices();

public:

	// ========== constructors and destructors ==========

	Sprite( const SpriteData &spriteData );
	~Sprite();

	// ========== getters and setters ==========


	// ========== API functions ==========

	bool load( std::string filepath = "" );

};

#endif

