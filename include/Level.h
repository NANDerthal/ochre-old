#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

#include "Collider.h"
#include "DisplayElement.h"

struct SpriteCollider {
	SpriteData spriteData;
	ColliderData colliderData;
};

class Level : public DisplayElement {

private:

	// Sprites (inherited) and colliders are associated by
	// ID (index in vector), "spriteID"
	std::vector < Collider* > colliders;

public:

	// ========== constructors and destructors ==========

	Level();
	~Level();

	// ========== get and set member variables ==========

	// ===== get =====

	const Collider* getCollider( unsigned int spriteID ) const;

	// ===== set =====

	void pushSpriteCollider( const SpriteCollider &spriteCollider );
	void pushCollider( const ColliderData &colliderData );

	// ========== API functions ==========

	void updatePhysics();

};

#endif

