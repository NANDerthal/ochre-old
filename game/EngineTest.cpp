#include "EngineTest.h"

#include <iostream>

#include <glm/fwd.hpp>
#include <glm/glm.hpp>

#include "GameObject.h"
#include "LevelTest.h"
#include "Sprite.h"

// ========== constructors and destructors ==========

EngineTest::EngineTest() {
	return;
} // EngineTest

EngineTest::~EngineTest() {
	return;
} // ~EngineTest


// ========== private member functions ==========

// ========== public member functions ==========

void EngineTest::run() {
	LevelTest* level = new LevelTest;
	pushElement( level );

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
	smileObject.setWorldLocation( glm::vec3( 300.0f, 20.0f, 1000.0f ) );

	GameObject udlrObject;
	udlrObject.setSpriteID( 1 );
	udlrObject.setWorldSize( glm::vec2( 100, 100 ) );
	udlrObject.setWorldLocation( glm::vec3( 300.0f, 20.0f, 0.0f ) );
	udlrObject.setRotationAngle( 60 );

	level->pushGameObject( smileObject );
	level->pushGameObject( udlrObject );

	// set up loop flags
	bool quit = false;

	glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );

	// game loop
	while ( !quit ) {

		// ===== handle events =====
		quit = handleEvents();

		// ===== render =====

		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		renderAll();

		// == draw to screen ==
		window->swapBuffer();

	}

	level = nullptr;

	return;
} // run

void EngineTest::runTest() {
	delay( 2000 );
	return;
}// runTest

