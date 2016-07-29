#ifndef COLLIDER_H
#define COLLIDER_H

#include <string>

#include "Asset.h"

struct ColliderData {
	std::string filepath;
};

class Collider : public Asset {

private:

	std::string filepath;

	// ========== disabled functions ==========	

	Collider() = delete;

public:

	// ========== constructors and destructors ==========

	Collider( const ColliderData& colliderData );
	~Collider() override;

	// ========== get and set member variables ==========

	std::string getFilepath() const override;

};

#endif

