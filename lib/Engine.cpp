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
}

Engine::~Engine() {
	delete window;
	window = nullptr;
	
	SDL_Quit();
}

// ========== functions for main.cpp ==========

bool Engine::init() {
	// Initialize SDL
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
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
	GLenum err = glewInit();
	if ( err != GLEW_OK ) {
		printf( "GLEW failed to load! GLEW error: %s\n", glewGetErrorString( err ) );
		return false; 
	}
	
	// Initialize openGL
	glEnable( GL_DEPTH_TEST );
	glViewport( 0, 0, window->getWidth(), window->getHeight() );

	return true;
}

// ========== API functions ==========

void Engine::setWindowTitle( const std::string &winTitle ) {
	window->setTitle( winTitle );
}

void Engine::setWindowSize( const int width, const int height ) {
	window->setSize( width, height );
}

void Engine::delay( int numMS ) {
	SDL_Delay( numMS );
}

