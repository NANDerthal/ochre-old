#include "Window.h"

// ========== constructors and destructors ==========
Window::Window() {
	window = NULL;
	glContext = NULL;
	
	title = "Untitled";
	width = 640;
	height = 480;
}

Window::~Window() {
	SDL_GL_DeleteContext( glContext );
	glContext = NULL;
	
	SDL_DestroyWindow( window );
	window = NULL;
}

// ========== public members ==========

// setting functions

void Window::setTitle( const std::string &winTitle ) {
	title = winTitle;
}

void Window::setSize( const int widthIn, const int heightIn ) {
	width = widthIn;
	height = heightIn;
}

// getting functions

std::string Window::getTitle() const {
	return title;
}

int Window::getWidth() const {
	return width;
}

int Window::getHeight() const {
	return height;
}

// Library-dependent functions

bool Window::init() {
	// Initialize window
	window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED, width,
								height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL ); 
	if ( window == NULL ) {
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}

	// Initialize openGL context
	glContext = SDL_GL_CreateContext( window );
	if ( glContext == NULL ) {
		printf( "GLContext could not be created! SDL_ERROR: %s\n", SDL_GetError() );
		return false;
	}
	
	return true;
}

void Window::update() {
	if ( window != NULL ) {
		SDL_SetWindowTitle( window, title.c_str() );
		SDL_SetWindowSize( window, width, height );
		glViewport( 0, 0, width, height );
	}
}

