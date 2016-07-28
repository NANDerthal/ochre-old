#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

#ifdef USING_WINDOWS
	#include <SDL.h>
#else
	#include <SDL2/SDL.h>
#endif

#include <glm/fwd.hpp>
#include <glm/glm.hpp>

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
	Uint32 time; // ms

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

