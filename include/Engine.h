#ifndef ENGINE_H
#define ENGINE_H

#include <string>

#include "game.hpp"
#include "Window.h"

class Engine {

private:

	Window* window;

public:

	// ========== constructors and destructors ==========
	
	Engine();
	~Engine();
	
	// ========== functions for main.cpp ==========
	// do not call these functions in your own code
	
	// friend necessary game functions
	friend void game::game();
	friend void game::test();
	
	// returns false if there is an error initializing
	// otherwise, returns true
	bool init();
	
	// run production version of game
	void run();
	
	// run test functions
	void runTest();
	
	// ========== API functions ==========
	
	void setWindowTitle( const std::string &winTitle );
	
	void setWindowSize( const int width, const int height );
	
	void delay( int numMS );

};

#endif

