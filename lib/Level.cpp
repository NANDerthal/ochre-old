#include "Level.h"

Level::Level() {
	return;
} // Level

Level::~Level() {
	for ( int i = 0; i < bgSprites.size(); ++i ) {
		delete bgSprites[i];
		bgSprites[i] = nullptr;
	}

	return;
}// Level
