#include "Renderer.h"

// ========== constructors and destructors ==========

Renderer::Renderer( int windowWidth, int windowHeight ) {
	// initialize camera
	GLfloat normalize3Init[] = {
		1.0f / (GLfloat)windowWidth,	0,								0,
		0,								1.0f / (GLfloat)windowHeight,	0,
		0,								0,								1.0f / 1000.0f
	};

	glm::mat3 normalize3 = glm::make_mat3( normalize3Init );
	normalize3 = glm::transpose( normalize3 );

	camera = new Camera( normalize3 );

	// initialize shaderProgram
	shaderProgram = new ShaderProgram( "sprite_shader" );

	// Convert pixel-perfect coordinates to normalized device coordinates
	// Normalized device coordinates are in the range [-1, 1], but combined
	// with the translateOrigin matrix, we have are using the range [0, 1]
	// Additionally, z-coordinates can now range from [-1000, 1000]

	GLfloat normalizeInit[] = {
		2.0f / (GLfloat)windowWidth,	0,								0,				0,
		0,								2.0f / (GLfloat)windowHeight,	0,				0,
		0,								0,								1.0f / 1000.0f,	0,
		0,								0,								0,				1
	};

	normalize = glm::make_mat4( normalizeInit );
	normalize = glm::transpose( normalize );

	// Translate origin ( 0, 0, 0 ) to the bottom left corner of the screen
	// Note that the positive z-axis points INTO the screen!
	// This is a LEFT-handed coordinate system!

	GLfloat translateOriginInit[] = {
		1,	0,	0,	-1,
		0,	1,	0,	-1,
		0,	0,	-1,	0,
		0,	0,	0,	1
	};

	translateOrigin = glm::make_mat4( translateOriginInit );
	translateOrigin = glm::transpose( translateOrigin );

	return;
} // Renderer

Renderer::~Renderer() {
	delete camera;
	camera = nullptr;

	delete shaderProgram;
	shaderProgram = nullptr;

	return;
}// ~Renderer

// ========== private member functions ==========

glm::mat4 Renderer::combineTransformations( const glm::vec3 &worldLocation,
											const float angle, const glm::vec3 &axis,
											const glm::vec2 &spriteSize,
											const glm::vec2 &outputSize ) const {
	// create matrix to scale object to outputSize
	glm::mat4 scale;
	GLfloat scaleX = (GLfloat)outputSize.x / (GLfloat)spriteSize.x;
	GLfloat scaleY = (GLfloat)outputSize.y / (GLfloat)spriteSize.y;
	scale = glm::scale( scale, glm::vec3( scaleX, scaleY, 1 ) );

	// create matrix to rotate object about its own coordinate system
	glm::mat4 rotate;
	// make it so that rotation is about the center (rather than the corner) of the object
	rotate = glm::translate( rotate, glm::vec3( 0.5 * outputSize.x, 0.5 * outputSize.y, 0 ) );
	rotate = glm::rotate( rotate, glm::radians( angle ), axis );
	rotate = glm::translate( rotate, glm::vec3( -0.5 * outputSize.x, -0.5 * outputSize.y, 0 ) );

	// create matrix to place object in world
	glm::mat4 transformWorldCoords;
	// make it so that positioning is based on the bottom center of the rotated object
	// recall that the current origin of the object is at the bottom left
	transformWorldCoords = glm::translate( transformWorldCoords, glm::vec3( -0.5 * outputSize.x, 0, 0 ) );
	transformWorldCoords = glm::translate( transformWorldCoords, worldLocation );

	// combine all transformations to single matrix
	return camera->getMatrix() *
		   translateOrigin * normalize *
		   transformWorldCoords * rotate * scale;
} // combineTransformations( worldPosition, angle, axis )

// ========== API functions ==========

void Renderer::renderObject( GameObject* object, Sprite* sprite ) {
	if ( !object->getMatrixValid() ) {
		glm::mat4 transformation = combineTransformations(
			object->getWorldLocation(),
			object->getRotationAngle(), object->getRotationAxis(),
			glm::vec2( sprite->getFrameWidth(), sprite->getFrameHeight() ),
			object->getWorldSize()
		);
		object->setTransformationMatrix( transformation );
	}

	shaderProgram->setActive();
	shaderProgram->setUniform( object->getTransformationMatrix() );
	shaderProgram->setUniform( sprite->getTextureID() );

	GLuint frameID = sprite->getFrameID( object->getAnimation(), object->getFrame() );
	shaderProgram->drawVertexArray( frameID );

	return;
} // renderObject

