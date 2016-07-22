#include "GameObject.h"

// ========== constructors and destructors ==========

GameObject::GameObject() {
	return;
} // GameObject

GameObject::~GameObject() {
	return;
} // ~GameObject

// ========== get and set member variables ==========

// ===== get =====

glm::vec3 GameObject::getWorldLocation() const {
	return worldLocation;
} // getWorldLocation

glm::vec3 GameObject::getVelocity() const {
	return velocity;
} // getVelocity

glm::vec2 GameObject::getWorldSize() const {
	return worldSize;
} // getWorldSize


// ANIMATION INFO

unsigned int GameObject::getAnimation() const {
	return animationData.animation;
} // getAnimation

unsigned int GameObject::getFrame() const {
	return animationData.frame;
} // getFrame

double GameObject::getFrameTime() const {
	return animationData.frameTime;
} // getFrameTime


// SPRITE ID INFO

unsigned int GameObject::getSpriteID() const {
	return spriteID;
} // getSpriteID


// INTERACTION INFO

bool GameObject::getCollidable() const {
	return collidable;
} // getCollidable

bool GameObject::getMovable() const {
	return movable;
} // getMovable

// ===== set =====

void GameObject::setWorldLocation( const glm::vec3 &worldLocationIn ) {
	worldLocation = worldLocationIn;
	return;
} // setWorldLocation

void GameObject::setVelocity( const glm::vec3 &velocityIn ) {
	velocity = velocityIn;
	return;
} // setVelocity

void GameObject::setWorldSize( const glm::vec2 &worldSizeIn ) {
	worldSize = worldSizeIn;
	return;
} // setWorldSize


// ANIMATION INFO

void GameObject::setAnimation( const unsigned int animationIn ) {
	animationData.animation = animationIn;
	return;
} // setAnimation

void GameObject::setFrame( const unsigned int frameIn ) {
	animationData.frame = frameIn;
	return;
} // setFrame

void GameObject::setFrameTime( const double frameTimeIn ) {
	animationData.frameTime = frameTimeIn;
	return;
} // setFrameTime


// SPRITE ID INFO

void GameObject::setSpriteID( const int spriteIDIn ) {
	spriteID = spriteIDIn;
	return;
} // setSpriteID


// INTERACTION INFO

void GameObject::setCollidable( const bool collidableIn ) {
	collidable = collidableIn;
	return;
} // setCollidable

void GameObject::setMovable( const bool movableIn ) {
	movable = movableIn;
	return;
} // setMovable

