#include "Engine.h"

// ========== constructors and destructors ==========

Engine::Engine() {
	window = new Window;
} // Engine

Engine::~Engine() {
	delete renderer;
	renderer = nullptr;

	for ( unsigned int i = 0; i < displayElements.size(); ++i ) {
		delete displayElements[i];
		displayElements[i] = nullptr;
	}

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

// ===== utility functions =====

void Engine::delay( int numMS ) {
	SDL_Delay( numMS );
} // delay

// ===== get and set member variables =====

unsigned int Engine::pushElement( DisplayElement* const element ) {
	displayElements.push_back( element );
	return ( displayElements.size() - 1 );
}

unsigned int Engine::getActiveElement() const {
	return activeElement;
} // getActiveElement

void Engine::setActiveElement( const unsigned int activeElementIn ) {
	activeElement = activeElementIn;
	return;
} // setActiveElement

// ===== handle events =====

bool Engine::handleEvents() {
	bool quit = false;

	while ( SDL_PollEvent( &eventQueue ) != 0 ) {
		switch ( eventQueue.type ) {

			case SDL_QUIT:
			quit = true;
			break;

			case SDL_APP_TERMINATING:
			displayElements[ activeElement ]->handle_APP_TERMINATING();
			break;

			case SDL_APP_LOWMEMORY:
			displayElements[ activeElement ]->handle_APP_LOWMEMORY();
			break;

			case SDL_APP_WILLENTERBACKGROUND:
			displayElements[ activeElement ]->handle_APP_WILLENTERBACKGROUND();
			break;

			case SDL_APP_DIDENTERBACKGROUND:
			displayElements[ activeElement ]->handle_APP_DIDENTERFOREGROUND();
			break;

			case SDL_WINDOWEVENT:
			displayElements[ activeElement ]->handle_WINDOWEVENT();
			break;

			case SDL_SYSWMEVENT:
			displayElements[ activeElement ]->handle_SYSWMEVENT();
			break;

			case SDL_KEYDOWN:
			displayElements[ activeElement ]->handle_KEYDOWN( eventQueue.key.keysym.sym );
			break;

			case SDL_KEYUP:
			displayElements[ activeElement ]->handle_KEYUP( eventQueue.key.keysym.sym );
			break;

			case SDL_TEXTEDITING:
			displayElements[ activeElement ]->handle_TEXTEDITING();
			break;

			case SDL_TEXTINPUT:
			displayElements[ activeElement ]->handle_TEXTINPUT();
			break;

			case SDL_KEYMAPCHANGED:
			displayElements[ activeElement ]->handle_KEYMAPCHANGED();
			break;

			case SDL_MOUSEMOTION:
			displayElements[ activeElement ]->handle_MOUSEMOTION();
			break;

			case SDL_MOUSEBUTTONDOWN:
			displayElements[ activeElement ]->handle_MOUSEBUTTONDOWN();
			break;

			case SDL_MOUSEBUTTONUP:
			displayElements[ activeElement ]->handle_MOUSEBUTTONUP();
			break;

			case SDL_MOUSEWHEEL:
			displayElements[ activeElement ]->handle_MOUSEWHEEL();
			break;

			case SDL_JOYAXISMOTION:
			displayElements[ activeElement ]->handle_JOYAXISMOTION();
			break;

			case SDL_JOYBALLMOTION:
			displayElements[ activeElement ]->handle_JOYBALLMOTION();
			break;

			case SDL_JOYHATMOTION:
			displayElements[ activeElement ]->handle_JOYHATMOTION();
			break;

			case SDL_JOYBUTTONDOWN:
			displayElements[ activeElement ]->handle_JOYBUTTONDOWN();
			break;

			case SDL_JOYBUTTONUP:
			displayElements[ activeElement ]->handle_JOYBUTTONUP();
			break;

			case SDL_JOYDEVICEADDED:
			displayElements[ activeElement ]->handle_JOYDEVICEADDED();
			break;

			case SDL_JOYDEVICEREMOVED:
			displayElements[ activeElement ]->handle_JOYDEVICEREMOVED();
			break;

			case SDL_CONTROLLERAXISMOTION:
			displayElements[ activeElement ]->handle_CONTROLLERAXISMOTION();
			break;

			case SDL_CONTROLLERBUTTONDOWN:
			displayElements[ activeElement ]->handle_CONTROLLERBUTTONDOWN();
			break;

			case SDL_CONTROLLERBUTTONUP:
			displayElements[ activeElement ]->handle_CONTROLLERBUTTONUP();
			break;

			case SDL_CONTROLLERDEVICEADDED:
			displayElements[ activeElement ]->handle_CONTROLLERDEVICEADDED();
			break;

			case SDL_CONTROLLERDEVICEREMOVED:
			displayElements[ activeElement ]->handle_CONTROLLERDEVICEREMOVED();
			break;

			case SDL_CONTROLLERDEVICEREMAPPED:
			displayElements[ activeElement ]->handle_CONTROLLERDEVICEREMAPPED();
			break;

			case SDL_FINGERDOWN:
			displayElements[ activeElement ]->handle_FINGERDOWN();
			break;

			case SDL_FINGERUP:
			displayElements[ activeElement ]->handle_FINGERUP();
			break;

			case SDL_FINGERMOTION:
			displayElements[ activeElement ]->handle_FINGERMOTION();
			break;

			case SDL_DOLLARGESTURE:
			displayElements[ activeElement ]->handle_DOLLARGESTURE();
			break;

			case SDL_DOLLARRECORD:
			displayElements[ activeElement ]->handle_DOLLARRECORD();
			break;

			case SDL_MULTIGESTURE:
			displayElements[ activeElement ]->handle_MULTIGESTURE();
			break;

			case SDL_CLIPBOARDUPDATE:
			displayElements[ activeElement ]->handle_CLIPBOARDUPDATE();
			break;

			case SDL_DROPFILE:
			displayElements[ activeElement ]->handle_DROPFILE();
			break;

			case SDL_AUDIODEVICEADDED:
			displayElements[ activeElement ]->handle_AUDIODEVICEADDED();
			break;

			case SDL_AUDIODEVICEREMOVED:
			displayElements[ activeElement ]->handle_AUDIODEVICEREMOVED();
			break;

			case SDL_RENDER_TARGETS_RESET:
			displayElements[ activeElement ]->handle_RENDER_TARGETS_RESET();
			break;

			case SDL_RENDER_DEVICE_RESET:
			displayElements[ activeElement ]->handle_RENDER_DEVICE_RESET();
			break;

			case SDL_USEREVENT:
			displayElements[ activeElement ]->handle_USEREVENT();
			break;

			case SDL_LASTEVENT:
			displayElements[ activeElement ]->handle_LASTEVENT();
			break;

			default:
			break;

		}
	}

	return quit;
} // handleEvents

// ===== rendering functions =====

void Engine::renderAll() {
	GameObject* obj;
	Sprite* objSprite;
	for ( unsigned int i = 0; i < displayElements.size(); ++i ) {
		for ( unsigned int j = 0; j < displayElements[i]->getNumObjects(); ++j ) {
			obj = displayElements[i]->getObject(j);
			objSprite = displayElements[i]->getSprite( obj->getSpriteID() );
			renderer->renderObject( obj, objSprite );
		}
	}
	return;
} // renderAll

