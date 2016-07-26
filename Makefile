CC = g++

INCLUDE_PATHS = -I./include -I./src -I./lib -I./test -I./game -I./backend/include -I./backend/lib

LINKER_FLAGS = -lSDL2 -lSDL2_ttf -lGLEW -lGL -lSOIL

MAIN = src/main.cpp

EXECUTABLE_MAIN = main.out
EXECUTABLE_NAMES = $(EXECUTABLE_MAIN)

EXCLUDE = Game-template
EXCLUDE := $(EXCLUDE:%=src/%.cpp)
EXCLUDE += $(EXCLUDE:src/%.cpp=include/%.h)
EXCLUDE += $(EXCLUDE:src/%.cpp=game/%.h)
EXCLUDE += $(EXCLUDE:src/%.cpp=game/%.cpp)

SOURCES = $(wildcard lib/*.cpp)
SOURCES += $(wildcard game/*.cpp)
SOURCES += $(wildcard backend/lib/*.cpp)
SOURCES := $(filter-out $(EXCLUDE), $(SOURCES))

OBJECTS = $(SOURCES:src/%.cpp=%.o)
MAIN_OBJECTS = test.o

COMPILER_FLAGS = -std=c++11
RELEASE_FLAGS = -w -O3 -DNDEBUG
DEBUG_FLAGS = --debug -DDEBUG -Wall -Werror -Wextra -pedantic
ENGINE_DEBUG_FLAGS = $(DEBUG_FLAGS)
ENGINE_DEBUG_FLAGS += -DENGINE_DEBUG

# ========== UBUNTU ==========

all : game-release

game-release: COMPILER_FLAGS += $(RELEASE_FLAGS)
game-release: MAIN_OBJECTS = main.o
game-release: $(EXECUTABLE_MAIN)

game-debug: COMPILER_FLAGS += $(DEBUG_FLAGS)
game-debug: MAIN_OBJECTS = main.o
game-debug: $(EXECUTABLE_MAIN)

engine-debug: COMPILER_FLAGS += $(ENGINE_DEBUG_FLAGS)
engine-debug: MAIN_OBJECTS = main.o
engine-debug: $(EXECUTABLE_MAIN)

main-leak:
	valgrind --leak-check=full --track-origins=yes --leak-resolution=high --show-reachable=yes ./$(EXECUTABLE_MAIN)

# ========== WINDOWS WITH MINGW ==========
INCLUDE_PATHS_W = -IC:\mingw_dev_lib\cross-tools\x86_64-w64-mingw32\include\SDL2 
LIBRARY_PATHS_W = -LC:\mingw_dev_lib\cross-tools\x86_64-w64-mingw32\lib
COMPILER_FLAGS_W = -Wl,-subsystem,windows -DUSING_WINDOWS
LINKER_FLAGS_W = -lSDL2main

allw: gamew

gamew: COMPILER_FLAGS += $(RELEASE_FLAGS)
gamew: MAIN_OBJECTS = main.o
gamew: addWinFlags
gamew: $(EXECUTABLE_MAIN)

addWinFlags: INCLUDE_PATHS += $(INCLUDE_PATHS_W)
addWinFlags: INCLUDE_PATHS += $(LIBRARY_PATHS_W)
addWinFlags: COMPILER_FLAGS += $(COMPILER_FLAGS_W)
addWinFlags: LINKER_FLAGS += $(LINKER_FLAGS_W)

# ====================
REMOVABLE = $(wildcard *.o) $(wildcard *.exe) $(wildcard *.out)

clean :
	rm  $(REMOVABLE)

%.o: src/%.cpp
	$(CC) $(INCLUDE_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c src/$*.cpp

%.out: %.o
	$(CC) $(OBJECTS) $(MAIN_OBJECTS) $(INCLUDE_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $*.out

# ========== OBJECTS ==========

# user-facing
Collider.o: include/Collider.h
Engine.o: include/Engine.h
GameObject.o: include/GameObject.h
Level.o: include/Level.h
Renderer.o: include/Renderer.h
Sprite.o: include/Sprite.h
Window.o: include/Window.h

Game.o: game/Game.h

# backend
Camera.o: backend/include/Camera.h
Shader.o: backend/include/Shader.h
ShaderProgram.o: backend/include/ShaderProgram.h
SpriteHelper.o: backend/include/SpriteHelper.h

main.o: $(OBJECTS) $(MAIN)

