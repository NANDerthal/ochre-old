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
	filepath = filepathIn
	return;
} // SpriteHelper

SpriteHelper::~SpriteHelper() {
	
	return;
} // ~SpriteHelper





