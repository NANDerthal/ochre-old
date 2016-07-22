#include "GameObject.h"

// ========== constructors and destructors ==========

GameObject::GameObject() {
	matrixValid = false;
	return;
} // GameObject

GameObject::~GameObject() {
	return;
} // ~GameObject

// ========== get and set member variables ==========

// ===== get =====

const float* GameObject::getTransformationMatrix() const {
	return glm::value_ptr( transformationMatrix );
} // getTransformationMatrix

bool GameObject::getMatrixValid() const {
	return matrixValid;
} // getMatrixValid

glm::vec3 GameObject::getWorldLocation() const {
	return worldLocation;
} // getWorldLocation

glm::vec2 GameObject::getWorldSize() const {
	return worldSize;
} // getWorldSize

float GameObject::getRotationAngle() const {
	return rotationAngle;
} // getRotationAngle

glm::vec3 GameObject::getRotationAxis() const {
	return rotationAxis;
} // getRotationAxis


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

glm::vec3 GameObject::getVelocity() const {
	return velocity;
} // getVelocity

// ===== set =====

void GameObject::setTransformationMatrix( const glm::mat4 &transformationMatrixIn ) {
	transformationMatrix = transformationMatrixIn;
	matrixValid = true;
	return;
} // setTransformationMatrix

void GameObject::setWorldLocation( const glm::vec3 &worldLocationIn ) {
	worldLocation = worldLocationIn;
	matrixValid = false;
	return;
} // setWorldLocation

void GameObject::setWorldSize( const glm::vec2 &worldSizeIn ) {
	worldSize = worldSizeIn;
	matrixValid = false;
	return;
} // setWorldSize

void GameObject::setRotationAngle( const float rotationAngleIn ) {
	rotationAngle = rotationAngleIn;
	matrixValid = false;
	return;
} // setRotationAngle

void GameObject::setRotationAxis( const glm::vec3 &rotationAxisIn ) {
	rotationAxis = rotationAxisIn;
	matrixValid = false;
	return;
} // setRotationAxis


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
	matrixValid = false;
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

void GameObject::setVelocity( const glm::vec3 &velocityIn ) {
	velocity = velocityIn;
	return;
} // setVelocity

