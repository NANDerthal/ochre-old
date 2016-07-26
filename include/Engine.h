#ifndef ENGINE_H
#define ENGINE_H

#include <string>

#include "Level.h"
#include "Renderer.h"
#include "Window.h"

class Engine {

protected:
// TODO hold vector of level interfaces instead of a single Level*
// this way we can select/toggle the current active element
	Level* level;
	Renderer* renderer;
	Window* window;

public:

	// ========== constructors and destructors ==========

	Engine();
	virtual ~Engine();

	// ========== functions for main.cpp ==========
	// do not call these functions in your own code

	// returns false if there is an error initializing
	// otherwise, returns true
	bool init();

	// run production version of game
	virtual void run() = 0;

	// run test functions
	virtual void runTest() = 0;

	// ========== API functions ==========
	// optimally, these should make it possible for the user to never touch the
	// underlying libraries used to implement the engine (SDL, OpenGL, etc)

	void delay( int numMS );
	// TODO add event handler to get event callbacks from interface
	// TODO add active element selector/toggler

};

#endif

