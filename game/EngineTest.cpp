#include "EngineTest.h"

#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// ========== constructors and destructors ==========

EngineTest::EngineTest() {
	shaderProgram = nullptr;
	return;
} // EngineTest

EngineTest::~EngineTest() {
	for ( unsigned int i = 0; i < sprites.size(); ++i ) {
		delete sprites[i];
		sprites[i] = nullptr;
	}

	delete shaderProgram;
	shaderProgram = nullptr;

	return;
} // ~EngineTest


// ========== public member functions ==========

void EngineTest::run() {
	// ===== set up transformation matrices =====

	GLfloat normalize[] = {
		1.0f / (GLfloat)window->getWidth(),	0,										0,	0,
		0,									1.0f / (GLfloat)window->getHeight(),	0,	0,
		0,									0,										1,	0,
		0,									0,										0,	1
	};
	
	glm::mat4 normalizeMatrix = glm::make_mat4( normalize );

	GLfloat translateOrigin[] = {
		2,	0,	0,	-1,
		0,	2,	0,	-1,
		0,	0,	2,	0,
		0,	0,	0,	1
	};
	
	glm::mat4 translateOriginMatrix = glm::make_mat4( translateOrigin );
	translateOriginMatrix = glm::transpose( translateOriginMatrix );

	GLfloat translateZSmile[] = {
		1,	0,	0,	0,
		0,	1,	0,	0,
		0,	0,	1,	0.9,
		0,	0,	0,	1
	};

	glm::mat4 translateZSmileMatrix = glm::make_mat4( translateZSmile );
	translateZSmileMatrix = glm::transpose( translateZSmileMatrix );

	glm::mat4 translateZUdlrMatrix( 1.0f );

	// ===== Load sprites =====

	enum SpriteSheets{ SMILE, UDLR, NUMSHEETS };

	SpriteData smileSprite = {
		"img/smile.png",
		512, 512,
		{1}
	};
	
	SpriteData udlrSprite = {
		"img/udlr-sheet.png",
		100, 100,
		{ 1, 4 }
	};

	sprites.reserve( NUMSHEETS );

	sprites.push_back( new Sprite( smileSprite ) );
	sprites.push_back( new Sprite( udlrSprite ) );

	for ( unsigned int i = 0; i < sprites.size(); ++i ) {
		if ( !sprites[i]->load() ) {
			printf( "Sprite loading failed! (From EngineTest) \n" );
		}
	}

	// ===== set up shader program =====

	shaderProgram = new ShaderProgram( "sprite_shader" );

	// ===== set loop flags =====
	bool quit = false;
	SDL_Event e;
	
	enum Press{ UP, RIGHT, DOWN, LEFT, NONE };
	
	Press press = NONE;

	while ( !quit ) {
		// ===== handle events =====
		while ( SDL_PollEvent( &e ) != 0 ) {
			if ( e.type == SDL_QUIT ) {
				quit = true;
			} else if ( e.type == SDL_KEYDOWN ) {
				// select surfaces based on key press
				switch ( e.key.keysym.sym ) {
					
					case SDLK_UP:
					press = UP;
					break;
					
					case SDLK_DOWN:
					press = DOWN;
					break;
					
					case SDLK_LEFT:
					press = LEFT;
					break;
					
					case SDLK_RIGHT:
					press = RIGHT;
					break;
					
					default:
					press = NONE;
					break;
					
				}
			}
		}
		
		const Uint8* keystate = SDL_GetKeyboardState( NULL );
		
		//continuous-response keys
		if ( keystate[SDL_SCANCODE_UP] ) {
			press = UP;
		} else if ( keystate[SDL_SCANCODE_DOWN] ) {
			press = DOWN;
		} else if ( keystate[SDL_SCANCODE_LEFT] ) {
			press = LEFT;
		} else if ( keystate[SDL_SCANCODE_RIGHT] ) {
			press = RIGHT;
		}

		// ===== render =====

		// == set state ==
		glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );

		// == use state ==
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		// == use shader program ==
		shaderProgram->setActive();

		// set transformations

		GLuint normalizeLoc = glGetUniformLocation( shaderProgram->shaderProgramID, "normalize" );
		glUniformMatrix4fv( normalizeLoc, 1, GL_FALSE, glm::value_ptr( normalizeMatrix ) );

		GLuint translateOriginLoc = glGetUniformLocation( shaderProgram->shaderProgramID, "translateOrigin" );
		glUniformMatrix4fv( translateOriginLoc, 1, GL_FALSE, glm::value_ptr( translateOriginMatrix ) );

		// draw smile sprite

		GLuint translateZLoc = glGetUniformLocation( shaderProgram->shaderProgramID, "translateZ" );
		glUniformMatrix4fv( translateZLoc, 1, GL_FALSE, glm::value_ptr( translateZSmileMatrix ) );

		glActiveTexture( GL_TEXTURE0 );
		glBindTexture( GL_TEXTURE_2D, sprites[SMILE]->spriteHelper->getTextureID() );
		glUniform1i( glGetUniformLocation( shaderProgram->shaderProgramID, "ourTexture"), 0 );

		glBindVertexArray( sprites[SMILE]->vertexArrays[0][0] );
		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );
		glBindVertexArray( 0 );

		// draw udlr sprite

		//GLuint translateZLoc = glGetUniformLocation( shaderProgram->shaderProgramID, "translateZ" );
		glUniformMatrix4fv( translateZLoc, 1, GL_FALSE, glm::value_ptr( translateZUdlrMatrix ) );

		glActiveTexture( GL_TEXTURE0 );
		glBindTexture( GL_TEXTURE_2D, sprites[UDLR]->spriteHelper->getTextureID() );
		glUniform1i( glGetUniformLocation( shaderProgram->shaderProgramID, "ourTexture"), 0 );

		if ( press != NONE ) {
			glBindVertexArray( sprites[UDLR]->vertexArrays[1][press] );
		} else {
			glBindVertexArray( sprites[UDLR]->vertexArrays[0][0] );
		}

		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );
		glBindVertexArray( 0 );

		// == draw to screen ==
		window->swapBuffer();
	}

	shaderProgram->setInactive();

	return;
} // run

void EngineTest::runTest() {
	delay( 2000 );
	return;
}// runTest

