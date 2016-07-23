#include "EngineTest.h"

#include <iostream>

#include <glm/fwd.hpp>
#include <glm/glm.hpp>

#include "GameObject.h"
#include "Sprite.h"

// ========== constructors and destructors ==========

EngineTest::EngineTest() {
	return;
} // EngineTest

EngineTest::~EngineTest() {
	return;
} // ~EngineTest


// ========== private member functions ==========

void EngineTest::renderAll() {
	GameObject* obj;
	Sprite* objSprite;
	for ( unsigned int i = 0; i < level->getNumObjects(); ++i ) {
		obj = level->getObject(i);
		objSprite = level->getSprite( obj->getSpriteID() );
		renderer->renderObject( obj, objSprite );
	}
	return;
}

// ========== public member functions ==========

void EngineTest::run() {
	level = new Level;

	// populate level
	SpriteData smileSprite = {
		"img/smile.png",
		512, 512,
		{1}
	};
	
	SpriteData udlrSprite = {
		"img/udlr-sheet.png",
		100, 100,
		{ 1, 4 }
	};

	level->pushSprite( smileSprite );
	level->pushSprite( udlrSprite );

	// TODO with more detailed GameObject constructor

	GameObject smileObject;
	smileObject.setSpriteID( 0 );
	smileObject.setWorldSize( glm::vec2( 200, 400 ) );
	smileObject.setWorldLocation( glm::vec3( 100, 100, 0.1 ) );

	GameObject udlrObject;
	udlrObject.setSpriteID( 1 );
	udlrObject.setWorldSize( glm::vec2( 200, 200 ) );
	udlrObject.setWorldLocation( glm::vec3( 300, 20, 0 ) );
	udlrObject.setRotationAngle( 30 );

	level->pushGameObject( smileObject );
	level->pushGameObject( udlrObject );

	// set up loop flags
	bool quit = false;
	SDL_Event e;

	glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );

	// game loop
	while ( !quit ) {

		// ===== handle events =====
		while ( SDL_PollEvent( &e ) != 0 ) {
			if ( e.type == SDL_QUIT ) {
				quit = true;
			}
		}

		// ===== render =====

		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		renderAll();

		// == draw to screen ==
		window->swapBuffer();

	}

	return;
} // run

void EngineTest::runTest() {
	delay( 2000 );
	return;
}// runTest

