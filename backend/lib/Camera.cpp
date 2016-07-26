#include "Camera.h"
#include <cstdio>

// ========== constructors and destructors ==========

Camera::Camera( const glm::mat3 &normalizeIn ) {
	normalize = normalizeIn;
	position = glm::vec3( 0.0f, 0.0f, 0.0f );
	target = glm::vec3( 0.0f, 0.0f, 1.0f );
	up = glm::vec3( 0.0f, 1.0f, 0.0f );
	fieldOfView = 90.0f; // pixel-perfect 2D at the camera's image plane
	matrixIsValid = false;
	usePerspective = true;
	return;
} // Camera

Camera::~Camera() {
	return;
} //~Camera

// ========== get and set member variables ==========

void Camera::setPosition( const glm::vec3 &positionIn ) {
	position = positionIn;
	matrixIsValid = false;
	return;
} // setPosition

void Camera::setTarget( const glm::vec3 &targetIn ) {
	target = targetIn;
	matrixIsValid = false;
	return;
} // setTarget

void Camera::setUp( const glm::vec3 &upIn ) {
	up = upIn;
	matrixIsValid = false;
	return;
} // setUp

void Camera::setFieldOfView( const float fov ) {
	fieldOfView = fov;
	matrixIsValid = false;
	return;
} // setFieldOfView

void Camera::setUsePerpective( const bool usePerspectiveIn ) {
	usePerspective = usePerspectiveIn;
	matrixIsValid = false;
	return;
} // setUsePerspective

glm::mat4 Camera::getMatrix() {
	if ( !matrixIsValid ) {
		// camera position
		// position, target, up
		// note that the target coordinate z-dimension is the opposite direction of
		// where you actually want to look - suppose you have z axis <-- and
		// object ------> camera
		// and want to look at the object. Then target should be in the --> direction
		// likewise, the position z-coord is negative of the world z-coord:
		// <---world positive z-direction; --->camera positive z-direction
		cameraMatrix = glm::lookAt( normalize * position, 
									glm::vec3( target.x, target.y, -target.z ), 
									normalize * up );

		if ( usePerspective ) {
			// perspective distortion
			glm::mat4 perspective = glm::perspective( glm::radians( fieldOfView ),
													  1.0f, // aspect ratio
													  0.0f, 1000.0f ); // clipping planes
			// correct glm incompatibility (glm does not add 1 * w-coordinate for perspective)
			perspective[3][3] = 1;

			cameraMatrix = perspective * cameraMatrix;
		}

		matrixIsValid = true;
	}

	return cameraMatrix;
}

