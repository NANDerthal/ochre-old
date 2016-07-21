#ifndef RENDERER_H
#define RENDERER_H

#ifdef USING_WINDOWS
	#include <glew.h>
#else
	#include <GL/glew.h>
#endif

#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Camera.h"

class Renderer {

private:

	Camera* camera;
	glm::mat4 normalize, translateOrigin, transformPerspective;

	// ========== disabled functions ==========

	Renderer() = delete;

	// ========== private member functions ==========

	glm::mat4 combineTransformations( const glm::vec3 &worldPosition, const float angle,
									  const glm::vec3 &axis, const glm::vec2 &objectSize,
									  const glm::vec2 &outputSize ) const;

public:

	// ========== constructors and destructors ==========

	Renderer( int windowWidth, int windowHeight );
	~Renderer();

	// ========== API functions ==========

};

#endif

