#ifndef CAMERA_H
#define CAMERA_H

#include <glm/fwd.hpp>
#include <glm/glm.hpp>

class Camera {

private:

	glm::mat4 cameraMatrix;
	bool matrixIsValid;

public:

	// ========== constructors and destructors ==========

	Camera();
	~Camera();

	// ========== get and set member variables ==========

	glm::mat4 getMatrix();

};

#endif

