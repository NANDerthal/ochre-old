#include "Collider.h"

// ========== constructors and destructors ==========

Collider::Collider( const ColliderData& colliderData ) {
	filepath = colliderData.filepath;
	return;
} // Collider

Collider::~Collider() {
	return;
} // ~Collider

// ========== get and set member variables ==========

std::string Collider::getFilepath() const {
	return filepath;
} // ~getFilePath

