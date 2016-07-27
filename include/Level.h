#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

#include "Collider.h"
#include "DisplayElement.h"
#include "GameObject.h"
#include "Sprite.h"

struct SpriteCollider {
	SpriteData spriteData;
	ColliderData colliderData;
};

class Level : public DisplayElement {

private:

	// Sprites and colliders are associated by ID (index in vector), "spriteID"
	std::vector < Sprite* > sprites;
	std::vector < Collider* > colliders;

	// Game objects will be accessed by their ID (index in vector), "objectID",
	// that is NOT related to the spriteIDs
	std::vector < GameObject* > gameObjects;

public:

	// ========== constructors and destructors ==========

	Level();
	~Level();

	// ========== get and set member variables ==========

	// ===== get =====

	unsigned int getNumObjects() const;

	// NOTE: these objects do not return pointers to const objects because
	// outside functions may need to change the returned objects' state
	GameObject* getObject( unsigned int objectID ) const;
	Sprite* getSprite( unsigned int spriteID ) const;

	const Collider* getCollider( unsigned int spriteID ) const;

	// ===== set =====

	void pushSpriteCollider( const SpriteCollider &spriteCollider );
	void pushSprite( const SpriteData &spriteData );
	void pushCollider( const ColliderData &colliderData );
	// TODO with more detailed GameObject constructor
	void pushGameObject( const GameObject &gameObject );

};

#endif

