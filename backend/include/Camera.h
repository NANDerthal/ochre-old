#ifndef CAMERA_H
#define CAMERA_H

#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {

private:

	glm::mat4 cameraMatrix;
	glm::mat3 normalize;
	glm::vec3 position, target, up;
	float fieldOfView; // degrees
	bool matrixIsValid, usePerspective;

public:

	// ========== constructors and destructors ==========

	Camera( const glm::mat3 &normalizeIn );
	~Camera();

	// ========== get and set member variables ==========

	void setPosition( const glm::vec3 &positionIn );
	void setTarget( const glm::vec3 &targetIn );
	void setUp( const glm::vec3 &upIn );
	void setFieldOfView( const float fov );
	void setUsePerpective( const bool usePerspectiveIn );

	glm::mat4 getMatrix();

};

#endif

