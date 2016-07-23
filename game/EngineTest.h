#ifndef ENGINETEST_H
#define ENGINETEST_H

#include "Engine.h"

/* 
 * NOTE: This is a derived class from the abstract base class Engine. Rename
 * or copy Game-template.* to Game.* to define your own Game class. This
 * particular instance is used by the developers for testing purposes.
 *
 * Main calls the run() function when the game is compiled and run without any
 * flags. This is where the game loop should go.
 *
 * Additionally, main calls the runTest() function when the game is compiled
 * and run with the -t or --test flag. Test suites should be defined here.
 */

class EngineTest : public Engine {

private:
	// Place any user-defined functions here

	void renderAll();

public:

	// ========== constructors and destructors ==========

	EngineTest();

	~EngineTest();

	// ========== public member functions ==========

	// Main game loop function (user-defined)
	void run() override;

	// Main test function (user-defined)
	void runTest() override;

};

#endif

