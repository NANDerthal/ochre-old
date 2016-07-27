#ifndef DISPLAY_ELEMENT_H
#define DISPLAY_ELEMENT_H

// NOTE: This is a base class which should not be changed.
// By default, all event handlers return without modifying anything.
// This way, derived classes can override only the events they need.

// Derived classes: Level, HUDElement

class DisplayElement {

public:

	// ========== constructors and destructors ==========

	DisplayElement();
	virtual ~DisplayElement();

	// ========== API functions ==========
	// NOTE: these are all event callback functions for SDL events
	// View all SDL events here: https://wiki.libsdl.org/SDL_EventType

	// NOTE: SDL leaves this event as unused
	// virtual void SDL_FIRSTEVENT();

	// Application events
	// NOTE: SDL_QUIT should be handled in the game loop in Game.cpp
	// virtual void SDL_QUIT();

	// Android, iOS and WinRT events
	virtual void handle_APP_TERMINATING();
	virtual void handle_APP_LOWMEMORY();
	virtual void handle_APP_WILLENTERBACKGROUND();
	virtual void handle_APP_DIDENTERBACKGROUND();
	virtual void handle_APP_WILLENTERFOREGROUND();
	virtual void handle_APP_DIDENTERFOREGROUND();

	// Window events
	virtual void handle_WINDOWEVENT();
	virtual void handle_SYSWMEVENT();

	// Keyboard events
	virtual void handle_KEYDOWN();
	virtual void handle_KEYUP();
	virtual void handle_TEXTEDITING();
	virtual void handle_TEXTINPUT();
	virtual void handle_KEYMAPCHANGED();

	// Mouse events
	virtual void handle_MOUSEMOTION();
	virtual void handle_MOUSEBUTTONDOWN();
	virtual void handle_MOUSEBUTTONUP();
	virtual void handle_MOUSEWHEEL();

	// Joystick events
	virtual void handle_JOYAXISMOTION();
	virtual void handle_JOYBALLMOTION();
	virtual void handle_JOYHATMOTION();
	virtual void handle_JOYBUTTONDOWN();
	virtual void handle_JOYBUTTONUP();
	virtual void handle_JOYDEVICEADDED();
	virtual void handle_JOYDEVICEREMOVED();

	// Controller events
	virtual void handle_CONTROLLERAXISMOTION();
	virtual void handle_CONTROLLERBUTTONDOWN();
	virtual void handle_CONTROLLERBUTTONUP();
	virtual void handle_CONTROLLERDEVICEADDED();
	virtual void handle_CONTROLLERDEVICEREMOVED();
	virtual void handle_CONTROLLERDEVICEREMAPPED();

	// Touch events
	virtual void handle_FINGERDOWN();
	virtual void handle_FINGERUP();
	virtual void handle_FINGERMOTION();

	// Gesture events
	virtual void handle_DOLLARGESTURE();
	virtual void handle_DOLLARRECORD();
	virtual void handle_MULTIGESTURE();

	// Clipboard events
	virtual void handle_CLIPBOARDUPDATE();

	// Drag and drop events
	virtual void handle_DROPFILE();

	// Audio hotplug events
	virtual void handle_AUDIODEVICEADDED();
	virtual void handle_AUDIODEVICEREMOVED();

	// Render events
	virtual void handle_RENDER_TARGETS_RESET();
	virtual void handle_RENDER_DEVICE_RESET();

	// These are for your use, and should be allocated with SDL_RegisterEvents()
	virtual void handle_USEREVENT();
	virtual void handle_LASTEVENT();

};

#endif

