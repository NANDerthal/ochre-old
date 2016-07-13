#ifndef ENGINE_H
#define ENGINE_H

#include <string>

#include "Window.h"

class Engine {

protected:

	Window* window;

public:

	// ========== constructors and destructors ==========
	
	Engine();
	~Engine();
	
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
	
	

};

#endif

