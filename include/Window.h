#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#ifdef USING_WINDOWS
	#include <SDL.h>
	#include <glew.h>
#else
	#include <SDL2/SDL.h>
	#include <GL/glew.h>
#endif

class Window {

private:
	SDL_Window* window;
	SDL_GLContext glContext;
	std::string title;
	int width, height;

public:

	// ========== constructors and destructors ==========
	
	Window();
	Window( const std::string &winTitle, const int widthIn, const int heightIn );
	~Window();
	
	// ========== public members ==========
	
	// ===== setting functions =====
	void setTitle( const std::string &winTitle );
	void setSize( const int widthIn, const int heightIn );
	
	// ===== getting functions =====
	std::string getTitle() const;
	int getWidth() const;
	int getHeight() const;
	
	// ===== library-dependent functions =====
	
	// create windows using variables set by setting functions
	bool init();

	// update to use set variables
	void update();

};

#endif

