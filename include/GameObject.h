#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glm/fwd.hpp>
#include <glm/glm.hpp>

struct GameObjectAnimation {
	unsigned int animation;
	unsigned int frame;
	double frameTime; // ms
};

// note: angles should be in degrees

class GameObject {

private:

	glm::vec3 worldLocation, velocity;
	glm::vec2 worldSize;
	float rotationAngle; // degrees
	GameObjectAnimation animationData;
	unsigned int spriteID; // sprite and collider ID (from Level)
	bool collidable, movable;

public:

	// ========== constructors and destructors ==========

	GameObject();
	~GameObject();

	// ========== get and set member variables ==========

	// ===== get =====

	glm::vec3 getWorldLocation() const;
	glm::vec3 getVelocity() const;
	glm::vec2 getWorldSize() const;

	unsigned int getAnimation() const;
	unsigned int getFrame() const;
	double getFrameTime() const;

	unsigned int getSpriteID() const;

	bool getCollidable() const;
	bool getMovable() const;

	// ===== set =====

	void setWorldLocation( const glm::vec3 &worldLocationIn );
	void setVelocity( const glm::vec3 &velocityIn );
	void setWorldSize( const glm::vec2 &worldSizeIn );

	void setAnimation( const unsigned int animationIn );
	void setFrame( const unsigned int frameIn );
	void setFrameTime( const double frameTimeIn );

	void setSpriteID( const int spriteIDIn );

	void setCollidable( const bool collidableIn );
	void setMovable( const bool movableIn );

};

#endif

