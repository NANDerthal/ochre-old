#include "Engine.h"

#include "game.hpp"

// ========== constructors and destructors ==========

Engine::Engine() {
	
}

Engine::~Engine() {
	
}

// ========== functions for main.cpp ==========

bool Engine::init() {
	return true;
}

void Engine::run() {
	game::main();
}

void Engine::runTest() {
	game::test();
}

// ========== API functions ==========


