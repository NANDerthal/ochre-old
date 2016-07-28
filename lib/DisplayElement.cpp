#include "DisplayElement.h"

// ========== constructors and destructors ==========

DisplayElement::DisplayElement() {
	return;
} // DisplayElement

DisplayElement::~DisplayElement() {
	return;
} // ~DisplayElement

// ========== API functions ==========

// ===== get and set member variables =====

// == get ==

unsigned int DisplayElement::getNumObjects() const{
	return gameObjects.size();
} // getNumObjects

GameObject* DisplayElement::getObject( unsigned int objectID ) const {
	return gameObjects[ objectID ];
} // getObject

Sprite* DisplayElement::getSprite( unsigned int spriteID ) const {
	return sprites[ spriteID ];
} // getSprite

// == set ==

void DisplayElement::pushSprite( const SpriteData &spriteData ) {
	sprites.push_back( new Sprite( spriteData ) );
	return;
} // pushSprite

void DisplayElement::pushGameObject( const GameObject &gameObject ) {
	// TODO with more detailed GameObject constructor
	GameObject* tmp = new GameObject;
	*tmp = gameObject;
	gameObjects.push_back( tmp );
	tmp = nullptr;
	return;
} // pushGameObject

// ===== Android, iOS and WinRT events =====

void DisplayElement::handle_APP_TERMINATING() {
	return;
} // handle_APP_TERMINATING

void DisplayElement::handle_APP_LOWMEMORY() {
	return;
} // handle_APP_LOWMEMORY

void DisplayElement::handle_APP_WILLENTERBACKGROUND() {
	return;
} // handle_APP_WILLENTERBACKGROUND

void DisplayElement::handle_APP_DIDENTERBACKGROUND() {
	return;
} // handle_APP_DIDENTERBACKGROUND

void DisplayElement::handle_APP_WILLENTERFOREGROUND() {
	return;
} // handle_APP_WILLENTERFOREGROUND

void DisplayElement::handle_APP_DIDENTERFOREGROUND() {
	return;
} // handle_APP_DIDENTERFOREGROUND


// ===== Window events =====

void DisplayElement::handle_WINDOWEVENT() {
	return;
} // handle_WINDOWEVENT

void DisplayElement::handle_SYSWMEVENT() {
	return;
} // handle_SYSWMEVENT


// ===== Keyboard events =====

void DisplayElement::handle_KEYDOWN( const SDL_Keycode keycode ) {
	return;
} // handle_KEYDOWN

void DisplayElement::handle_KEYUP( const SDL_Keycode keycode ) {
	return;
} // handle_KEYUP

void DisplayElement::handle_TEXTEDITING() {
	return;
} // handle_TEXTEDITING

void DisplayElement::handle_TEXTINPUT() {
	return;
} // handle_TEXTINPUT

void DisplayElement::handle_KEYMAPCHANGED() {
	return;
} // handle_KEYMAPCHANGED


// ===== Mouse events =====

void DisplayElement::handle_MOUSEMOTION() {
	return;
} // handle_MOUSEMOTION

void DisplayElement::handle_MOUSEBUTTONDOWN() {
	return;
} // handle_MOUSEBUTTONDOWN

void DisplayElement::handle_MOUSEBUTTONUP() {
	return;
} // handle_MOUSEBUTTONUP

void DisplayElement::handle_MOUSEWHEEL() {
	return;
} // handle_MOUSEWHEEL


// ===== Joystick events =====

void DisplayElement::handle_JOYAXISMOTION() {
	return;
} // handle_JOYAXISMOTION

void DisplayElement::handle_JOYBALLMOTION() {
	return;
} // handle_JOYBALLMOTION

void DisplayElement::handle_JOYHATMOTION() {
	return;
} // handle_JOYHATMOTION

void DisplayElement::handle_JOYBUTTONDOWN() {
	return;
} // handle_JOYBUTTONDOWN

void DisplayElement::handle_JOYBUTTONUP() {
	return;
} // handle_JOYBUTTONUP

void DisplayElement::handle_JOYDEVICEADDED() {
	return;
} // handle_JOYDEVICEADDED

void DisplayElement::handle_JOYDEVICEREMOVED() {
	return;
} // handle_JOYDEVICEREMOVED


// ===== Controller events =====

void DisplayElement::handle_CONTROLLERAXISMOTION() {
	return;
} // handle_CONTROLLERAXISMOTION

void DisplayElement::handle_CONTROLLERBUTTONDOWN() {
	return;
} // handle_CONTROLLERBUTTONDOWN

void DisplayElement::handle_CONTROLLERBUTTONUP() {
	return;
} // handle_CONTROLLERBUTTONUP

void DisplayElement::handle_CONTROLLERDEVICEADDED() {
	return;
} // handle_CONTROLLERDEVICEADDED

void DisplayElement::handle_CONTROLLERDEVICEREMOVED() {
	return;
} // handle_CONTROLLERDEVICEREMOVED

void DisplayElement::handle_CONTROLLERDEVICEREMAPPED() {
	return;
} // handle_CONTROLLERDEVICEREMAPPED


// ===== Touch events =====

void DisplayElement::handle_FINGERDOWN() {
	return;
} // handle_FINGERDOWN

void DisplayElement::handle_FINGERUP() {
	return;
} // handle_FINGERUP

void DisplayElement::handle_FINGERMOTION() {
	return;
} // handle_FINGERMOTION


// ===== Gesture events =====

void DisplayElement::handle_DOLLARGESTURE() {
	return;
} // handle_DOLLARGESTURE

void DisplayElement::handle_DOLLARRECORD() {
	return;
} // handle_DOLLARRECORD

void DisplayElement::handle_MULTIGESTURE() {
	return;
} // handle_MULTIGESTURE


// ===== Clipboard events =====

void DisplayElement::handle_CLIPBOARDUPDATE() {
	return;
} // handle_CLIPBOARDUPDATE


// ===== Drag and drop events =====

void DisplayElement::handle_DROPFILE() {
	return;
} // handle_DROPFILE


// ===== Audio hotplug events =====

void DisplayElement::handle_AUDIODEVICEADDED() {
	return;
} // handle_AUDIODEVICEADDED

void DisplayElement::handle_AUDIODEVICEREMOVED() {
	return;
} // handle_AUDIODEVICEREMOVED


// ===== Render events =====

void DisplayElement::handle_RENDER_TARGETS_RESET() {
	return;
} // handle_RENDER_TARGETS_RESET

void DisplayElement::handle_RENDER_DEVICE_RESET() {
	return;
} // handle_RENDER_DEVICE_RESET


// ===== These are for your use, and should be allocated with SDL_RegisterEvents() =====

void DisplayElement::handle_USEREVENT() {
	return;
} // handle_USEREVENT

void DisplayElement::handle_LASTEVENT() {
	return;
} // handle_LASTEVENT

