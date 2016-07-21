#include "Camera.h"

// ========== constructors and destructors ==========

Camera::Camera() {
	cameraMatrix = glm::mat4( 1.0f );
	matrixIsValid = false;
	return;
} // Camera

Camera::~Camera() {
	return;
} //~Camera

// ========== get and set member variables ==========

glm::mat4 Camera::getMatrix() {
	if ( matrixIsValid ) {
		return cameraMatrix;
	} else {
		// TODO: calculate matrix based on camera parameters
	}

	return cameraMatrix;
}

