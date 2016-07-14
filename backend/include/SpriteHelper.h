#ifndef SPRITE_HELPER_H
#define SPRITE_HELPER_H

#include <string>

#ifdef USING_WINDOWS
	#include <glew.h>
#else
	#include <GL/glew.h>
#endif

class SpriteHelper {

private:

	std::string filepath;

public:

	// ========== constructors and destructors ==========

	SpriteHelper( const std::string filepathIn = "" );
	~SpriteHelper();

	// ========== getters and setters ==========

	// ========== API functions ==========

};

#endif

