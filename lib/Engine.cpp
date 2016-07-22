#include "Engine.h"

#ifdef USING_WINDOWS
	#include <SDL.h>
	#include <glew.h>
#else
	#include <SDL2/SDL.h>
	#include <GL/glew.h>
#endif

// ========== constructors and destructors ==========

Engine::Engine() {
	window = new Window;
} // Engine

Engine::~Engine() {
	delete renderer;
	renderer = nullptr;

	delete level;
	level = nullptr;

	delete window;
	window = nullptr;
	
	SDL_Quit();
} // ~Engine

// ========== functions for main.cpp ==========

bool Engine::init() {
	// Initialize SDL
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL error: %s\n", SDL_GetError() );
		return false;
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	// Initialize window and OpenGL context
	if ( !window->init() ) {
		printf( "Failed to initialize window!" );
		return false;
	}

	// Initialize GLEW (load OpenGL functionality)

	glewExperimental = GL_TRUE;

	GLenum glewError = glewInit();

	// clear OpenGL error that results from GLEW initialization
	GLenum glGlewError = glGetError();
	
	if ( glewError != GLEW_OK ) {
		printf( "GLEW failed to load! GLEW error: %s\n", glewGetErrorString( glewError ) );
		printf( "GLEW failed to load! OpenGL error: %d\n", glGlewError );
		return false;
	}

	// Initialize openGL
	glViewport( 0, 0, window->getWidth(), window->getHeight() );
	glEnable( GL_DEPTH_TEST );

	// Initialize renderer
	renderer = new Renderer( window->getWidth(), window->getHeight() );

	return true;
} // init

// ========== API functions ==========

void Engine::delay( int numMS ) {
	SDL_Delay( numMS );
} // delay

