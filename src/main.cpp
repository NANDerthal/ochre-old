#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "Engine.h"

#ifdef main
	#undef main
#endif

void helpOut();
void invalidOut();

int main( int argc, char* argv[] ) {
	
	// Get option flags
	
	int test = 0;
	
	if ( argc > 2 ) {
		invalidOut();
	} else if ( argc == 1 ) {
		test = 0;
	} else if ( argc == 2 ) {
		if ( !strcmp( "-h", argv[1] ) || !strcmp( "--help", argv[1] ) ) {
			helpOut();
		} else if ( !strcmp( "-t", argv[1] ) || !strcmp( "--test", argv[1] ) ) {
			test = 1;
		} else {
			invalidOut();
		}
	} else {
		invalidOut();
	}
	
	// Run game
	
	Engine game;
	
	if ( !game.init() ) {
		printf("Error initializing game!\n");
		exit(1);
	}
	
	if ( !test ) {
		game.run();
	} else {
		game.runTest();
	}

	return 0;

}

void helpOut() {
	printf( "Use -t to run tests, and no arguments to run production code.\n" );
	exit(0);
}

void invalidOut() {
	printf( "Invalid input. Use -h for help.\n" );
	exit(1);
}

