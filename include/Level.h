#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

#include "Sprite.h"

class Level {

private:

	std::vector < Sprite* > bgSprites;

public:

	Level();
	~Level();

};

#endif

