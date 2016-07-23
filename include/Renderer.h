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
#include "GameObject.h"
#include "ShaderProgram.h"
#include "Sprite.h"

// note: angles should be in degrees

class Renderer {

private:

	Camera* camera;
	ShaderProgram* shaderProgram;
	glm::mat4 normalize, translateOrigin, transformPerspective;

	// ========== disabled functions ==========

	Renderer() = delete;

	// ========== private member functions ==========

	glm::mat4 combineTransformations( const glm::vec3 &worldLocation, const float angle,
									  const glm::vec3 &axis, const glm::vec2 &spriteSize,
									  const glm::vec2 &outputSize ) const;

public:

	// ========== constructors and destructors ==========

	Renderer( int windowWidth, int windowHeight );
	~Renderer();

	// ========== API functions ==========

	void renderObject( GameObject* object, Sprite* sprite );

};

#endif

