#include "Level.h"

// ========== constructors and destructors ==========

Level::Level() {
	return;
} // Level

Level::~Level() {
	for ( unsigned int i = 0; i < gameObjects.size(); ++i ) {
		delete gameObjects[i];
		gameObjects[i] = nullptr;
	}

	for ( unsigned int i = 0; i < colliders.size(); ++i ) {
		delete colliders[i];
		colliders[i] = nullptr;
	}

	for ( unsigned int i = 0; i < sprites.size(); ++i ) {
		delete sprites[i];
		sprites[i] = nullptr;
	}

	return;
}// Level

// ========== get and set member variables ==========

// ===== get =====

unsigned int Level::getNumObjects() const{
	return gameObjects.size();
} // getNumObjects

GameObject const * Level::getObject( unsigned int objectID ) const {
	return gameObjects[ objectID ];
} // getObject

Sprite const * Level::getSprite( unsigned int spriteID ) const {
	return sprites[ spriteID ];
} // getSprite

Collider const * Level::getCollider( unsigned int spriteID ) const {
	return colliders[ spriteID ];
} // getCollider

// ===== set =====

void Level::pushSpriteCollider( const SpriteCollider &spriteCollider ) {
	pushSprite( spriteCollider.spriteData );
	pushCollider( spriteCollider.colliderData );
	return;
} // pushSpriteCollider

void Level::pushSprite( const SpriteData &spriteData ) {
	sprites.push_back( new Sprite( spriteData ) );
	return;
} // pushSprite

void Level::pushCollider( const ColliderData &colliderData ) {
	colliders.push_back( new Collider( colliderData ) );
	return;
} // pushCollider

void Level::pushGameObject() {
	// TODO
	return;
} // pushGameObject

