#ifndef ENGINE_H
#define ENGINE_H

class Engine {

private:

public:

	// ========== constructors and destructors ==========
	
	Engine();
	~Engine();
	
	// ========== functions for main.cpp ==========
	// do not call these functions in your own code
	
	// returns false if there is an error initializing
	// otherwise, returns true
	bool init();
	
	// run production version of game
	void run();
	
	// run test functions
	void runTest();
	
	// ========== API functions ==========
	
	

};

#endif

