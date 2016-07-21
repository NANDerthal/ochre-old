#include "Renderer.h"

// ========== constructors and destructors ==========

Renderer::Renderer( int windowWidth, int windowHeight ) {
	camera = new Camera;

	// Convert pixel-perfect coordinates to normalized device coordinates
	// Normalized device coordinates are in the range [-1, 1], but combined
	// with the translateOrigin matrix, we have are using the range [0, 1]

	GLfloat normalizeInit[] = {
		1.0f / (GLfloat)windowWidth,	0,								0,	0,
		0,								1.0f / (GLfloat)windowHeight,	0,	0,
		0,								0,								1,	0,
		0,								0,								0,	1
	};

	normalize = glm::make_mat4( normalizeInit );
	normalize = glm::transpose( normalize );

	// Translate origin ( 0, 0, 0 ) to the bottom left corner of the screen
	// Note that the positive z-axis points INTO the screen!
	// This is a LEFT-handed coordinate system!

	GLfloat translateOriginInit[] = {
		2,	0,	0,	-1,
		0,	2,	0,	-1,
		0,	0,	2,	0,
		0,	0,	0,	1
	};

	translateOrigin = glm::make_mat4( translateOriginInit );
	translateOrigin = glm::transpose( translateOrigin );

	return;
} // Renderer

Renderer::~Renderer() {
	return;
}// ~Renderer

// ========== private member functions ==========

glm::mat4 Renderer::combineTransformations( const glm::vec3 &worldPosition,
											const float angle, const glm::vec3 &axis,
											const glm::vec2 &objectSize,
											const glm::vec2 &outputSize ) const {
	// create matrix to scale object to outputSize
	glm::mat4 scale;
	GLfloat scaleX = (GLfloat)outputSize.x / (GLfloat)objectSize.x;
	GLfloat scaleY = (GLfloat)outputSize.y / (GLfloat)objectSize.y;
	scale = glm::scale( scale, glm::vec3( scaleX, scaleY, 1 ) );

	// create matrix to rotate object about its own coordinate system
	glm::mat4 rotate;
	// make it so that rotation is about the center (rather than the corner) of the object
	rotate = glm::translate( rotate, glm::vec3( -0.5 * objectSize.x, -0.5 * objectSize.y, 0 ) );
	rotate = glm::rotate( rotate, glm::radians( angle ), axis );

	// create matrix to place object in world
	glm::mat4 transformWorldCoords;
	// make it so that positioning is based on the bottom center of the object
	// recall that the current origin of the object is at the center
	transformWorldCoords = glm::translate( transformWorldCoords, glm::vec3( 0, 0.5 * objectSize.y, 0 ) );
	transformWorldCoords = glm::translate( transformWorldCoords, worldPosition );

	// combine all transformations to single matrix
	return transformPerspective * camera->getMatrix() *
		   translateOrigin * normalize *
		   transformWorldCoords * rotate * scale;
} // combineTransformations( worldPosition, angle, axis )

