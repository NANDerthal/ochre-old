#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

struct GameObjectAnimation {
	unsigned int animation;
	unsigned int frame;
	double frameTime; // ms
};

// note: angles should be in degrees

class GameObject {

private:

	glm::mat4 transformationMatrix;
	glm::vec3 worldLocation, rotationAxis, velocity;
	glm::vec2 worldSize;
	float rotationAngle; // degrees
	GameObjectAnimation animationData;
	unsigned int spriteID; // sprite and collider ID (from Level)
	bool collidable, movable, matrixValid;

public:

	// ========== constructors and destructors ==========

	GameObject();
	~GameObject();

	// ========== get and set member variables ==========

	// ===== get =====

	bool getMatrixValid() const;
	const float* getTransformationMatrix() const;
	glm::vec3 getWorldLocation() const;
	glm::vec2 getWorldSize() const;
	float getRotationAngle() const;
	glm::vec3 getRotationAxis() const;

	unsigned int getAnimation() const;
	unsigned int getFrame() const;
	double getFrameTime() const;

	unsigned int getSpriteID() const;

	bool getCollidable() const;
	bool getMovable() const;
	glm::vec3 getVelocity() const;

	// ===== set =====

	void setTransformationMatrix( const glm::mat4 &transformationMatrixIn );
	void setWorldLocation( const glm::vec3 &worldLocationIn );
	void setWorldSize( const glm::vec2 &worldSizeIn );
	void setRotationAngle( const float rotationAngleIn );
	void setRotationAxis( const glm::vec3 &rotationAxisIn );

	void setAnimation( const unsigned int animationIn );
	void setFrame( const unsigned int frameIn );
	void setFrameTime( const double frameTimeIn );

	void setSpriteID( const int spriteIDIn );

	void setCollidable( const bool collidableIn );
	void setMovable( const bool movableIn );
	void setVelocity( const glm::vec3 &velocityIn );

};

#endif

