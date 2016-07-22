#ifndef COLLIDER_H
#define COLLIDER_H

#include <string>

struct ColliderData {
	std::string filepath;
};

class Collider {

private:

	std::string filepath;

	// ========== disabled functions ==========	

	Collider() = delete;

public:

	// ========== constructors and destructors ==========

	Collider( const ColliderData& colliderData );
	~Collider();

};

#endif
