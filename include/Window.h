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

/*
 * This class is a member of Engine.
 * Therefore, public members must abstract away library-related details.
 */

class Window {

private:

	SDL_Window* window;
	SDL_GLContext glContext;
	std::string title;
	int width, height;
	bool updateMeta;

public:

	// ========== constructors and destructors ==========
	
	Window();
	Window( const std::string &winTitle, const int widthIn, const int heightIn );
	~Window();
	
	// ========== engine internal functions ==========
	// do not call these functions in your own code
	
	// create windows using variables set by setting functions
	bool init();

	// ========== API functions ==========
	
	// ===== setting functions =====
	void setTitle( const std::string &winTitle );
	void setSize( const int widthIn, const int heightIn );
	
	// ===== getting functions =====
	std::string getTitle() const;
	int getWidth() const;
	int getHeight() const;
	
	// ===== drawing functions =====
	// update to use set variables
	void swapBuffer();
	void update();

};

#endif

