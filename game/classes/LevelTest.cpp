#include "LevelTest.h"

LevelTest::LevelTest() {
	return;
} // LevelTest

void LevelTest::updateVelocityX( int objectID, float vel ) {
	gameObjects[ objectID ]->setVelocity( glm::vec3( vel, 0, 0 ) );
	return;
} // updateVelocity

void LevelTest::updateVelocityY( int objectID, float vel ) {
	gameObjects[ objectID ]->setVelocity( glm::vec3( 0, vel, 0 ) );
	return;
} // updateVelocityY

void LevelTest::handle_KEYDOWN( const SDL_Keycode keycode ) {
	switch ( keycode ) {
		case SDLK_UP:
		case SDLK_w:
		updateVelocityY( 0, 1 );
		break;

		case SDLK_DOWN:
		case SDLK_s:
		updateVelocityY( 0, -1 );
		break;

		case SDLK_LEFT:
		case SDLK_a:
		updateVelocityX( 0, -1 );
		break;

		case SDLK_RIGHT:
		case SDLK_d:
		updateVelocityX( 0, 1 );
		break;

		default:
		break;
	}
	return;
} // handle_KEYDOWN

void LevelTest::handle_KEYUP( const SDL_Keycode keycode ) {
	switch ( keycode ) {
		case SDLK_UP:
		case SDLK_w:
		updateVelocityY( 0, 0 );
		break;

		case SDLK_DOWN:
		case SDLK_s:
		updateVelocityY( 0, 0 );
		break;

		case SDLK_LEFT:
		case SDLK_a:
		updateVelocityX( 0, 0 );
		break;

		case SDLK_RIGHT:
		case SDLK_d:
		updateVelocityX( 0, 0 );
		break;

		default:
		break;
	}
	return;
} // handle_KEYUP

