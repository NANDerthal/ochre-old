#include "EngineTest.h"

// ========== constructors and destructors ==========

EngineTest::EngineTest() {
	sprite = nullptr;
	shaderProgram = nullptr;
	return;
} // EngineTest

EngineTest::~EngineTest() {
	delete sprite;
	sprite = nullptr;

	delete shaderProgram;
	shaderProgram = nullptr;
	
	return;
} // ~EngineTest


// ========== public member functions ==========

void EngineTest::run() {
	SpriteData smileSprite = {
		"img/smile.png",
		512, 512,
		{1}
	};

	sprite = new Sprite( smileSprite );

	shaderProgram = new ShaderProgram( "sprite_shader" );
	
	if ( !sprite->load() ) {
		printf( "Sprite loading failed! (From EngineTest) \n" );
	}

	// ===== set loop flags =====
	bool quit = false;
	SDL_Event e;

	while ( !quit ) {
		// ===== handle events =====
		while ( SDL_PollEvent( &e ) != 0 ) {
			if ( e.type == SDL_QUIT ) {
				quit = true;
			}
		}
		
		// ===== render =====

		// == set state ==
		glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
		
		// == use state ==
		glClear( GL_COLOR_BUFFER_BIT );
		
		// == use shader program ==
		shaderProgram->setActive();

		glActiveTexture( GL_TEXTURE0 );
		glBindTexture( GL_TEXTURE_2D, sprite->spriteHelper->getTextureID() );
		glUniform1i( glGetUniformLocation( shaderProgram->shaderProgramID, "ourTexture"), 0 );

		glBindVertexArray( sprite->vertexArrays[0][0] );
		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );
		glBindVertexArray( NULL );

		// == draw to screen ==
		window->swapBuffer();
	}

	return;
} // run

void EngineTest::runTest() {
	delay( 2000 );
}// runTest

