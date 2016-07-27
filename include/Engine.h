#ifndef ENGINE_H
#define ENGINE_H

#include <string>

#ifdef USING_WINDOWS
	#include <SDL.h>
	#include <glew.h>
#else
	#include <SDL2/SDL.h>
	#include <GL/glew.h>
#endif

#include "DisplayElement.h"
#include "Renderer.h"
#include "Window.h"

class Engine {

protected:

	std::vector< DisplayElement* > displayElements;
	Renderer* renderer;
	Window* window;
	SDL_Event eventQueue;
	unsigned int activeElement;

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

	// ===== utility functions =====

	void delay( int numMS );

	// ===== get and set member variables =====

	// returns the ID of the element that was pushed
	unsigned int pushElement( const DisplayElement* element );

	unsigned int getActiveElement() const;

	void setActiveElement( const unsigned int activeElement );

	// ===== handle events =====

	// returns true if a quit event was detected
	bool handleEvents();

	// ===== rendering functions =====

	void renderAll();

};

#endif

