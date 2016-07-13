#include "Window.h"

// ========== constructors and destructors ==========
Window::Window() {
	window = NULL;
	glContext = NULL;
	
	title = "Untitled";
	width = 640;
	height = 480;
	
	updateMeta = true;
	
	return;
} // Window()

Window::Window( const std::string &winTitle, const int widthIn, const int heightIn ) {
	window = NULL;
	glContext = NULL;
	
	setTitle( winTitle );
	setSize( widthIn, heightIn );
	
	updateMeta = true;
	
	return;
} // Window( winTitle, widthIn, heightIn )

Window::~Window() {
	SDL_GL_DeleteContext( glContext );
	glContext = NULL;
	
	SDL_DestroyWindow( window );
	window = NULL;
} // ~Window

// ========== engine internal functions ==========

bool Window::init() {
	// Initialize window
	window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED, width,
								height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL ); 
	if ( window == NULL ) {
		printf( "Window could not be created! SDL error: %s\n", SDL_GetError() );
		return false;
	}

	// Initialize openGL context
	glContext = SDL_GL_CreateContext( window );
	if ( glContext == NULL ) {
		printf( "GLContext could not be created! SDL error: %s\n", SDL_GetError() );
		return false;
	}
	
	updateMeta = false;
	
	return true;
} // init

// ========== API functions ==========

// ===== setting functions =====

void Window::setTitle( const std::string &winTitle ) {
	title = winTitle;
	updateMeta = true;
	return;
} // setTitle

void Window::setSize( const int widthIn, const int heightIn ) {
	width = widthIn;
	height = heightIn;
	updateMeta = true;
	return;
} // setSize

// ===== getting functions =====

std::string Window::getTitle() const {
	return title;
} // getTitle

int Window::getWidth() const {
	return width;
} // getWidth

int Window::getHeight() const {
	return height;
} // getHeight

// ===== drawing functions =====

// update to use set variables
void Window::update() {
	if ( updateMeta ) {
		SDL_SetWindowTitle( window, title.c_str() );
		SDL_SetWindowSize( window, width, height );
		glViewport( 0, 0, width, height );
		updateMeta = false;
	}
	
	return;
} // update

