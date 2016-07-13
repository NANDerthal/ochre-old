#ifndef GAME_H
#define GAME_H

#include "Engine.h"

/* 
 * NOTE: This is a derived class from the abstract base class Engine. Rename
 * or copy Game-template.* to Game.* to define your own Game class.
 *
 * It can make use of the functions defined in Engine, and is meant to hold
 * user-defined functions that define the behavior of the actual game. None of
 * the functions in this class are implemented, and are intended to be defined
 * by the user of this engine library.
 *
 * Main calls the run() function when the game is compiled and run without any
 * flags. This is where the game loop should go.
 *
 * Additionally, main calls the runTest() function when the game is compiled
 * and run with the -t or --test flag. Test suites should be defined here.
 */

class Game : public Engine {

private:
	// Place any user-defined functions here

public:
	
	// Main game loop function (user-defined)
	void run() override;
	
	// Main test function (user-defined)
	void runTest() override;

};

#endif

