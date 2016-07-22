#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glm/fwd.hpp>
#include <glm/glm.hpp>

struct GameObjectAnimation {
	unsigned int animation;
	unsigned int frame;
	double frameTime; // ms
}

// note: angles should be in degrees

class GameObject {

private:

	glm::vec3 worldLocation, velocity;
	float rotationAngle; // degrees
	GameObjectAnimation animationData;
	int spriteID; // sprite and collider ID (from Level)
	bool movable;

public:

	// ========== constructors and destructors ==========

	GameObject();
	~GameObject();

};

#endif

