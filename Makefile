CC = g++

INCLUDE_PATHS = -I./include -I./src -I./lib

LINKER_FLAGS = -lSDL2 -lSDL2_ttf -lGLEW -lGL -lSOIL

MAIN = src/main.cpp

EXECUTABLE_MAIN = main.out
EXECUTABLE_NAMES = $(EXECUTABLE_MAIN)

#EXCLUDE = Game SaveFile
#EXCLUDE := $(EXCLUDE:%=src/%.cpp)
#EXCLUDE += $(EXCLUDE:src/%.cpp=include/%.h)

SOURCES = $(wildcard lib/*.cpp)
SOURCES := $(filter-out $(EXCLUDE), $(SOURCES))

OBJECTS = $(SOURCES:src/%.cpp=%.o)
MAIN_OBJECTS = test.o

COMPILER_FLAGS = -std=c++11 -w #-Wall -Werror -Wextra -pedantic
RELEASE_FLAGS = -O3 -DNDEBUG
DEBUG_FLAGS = --debug -DDEBUG

# ========== UBUNTU ==========

all : game-release

game-release: COMPILER_FLAGS += $(RELEASE_FLAGS)
game-release: MAIN_OBJECTS = main.o
game-release: $(EXECUTABLE_MAIN)

game-debug: COMPILER_FLAGS += $(DEBUG_FLAGS)
game-debug: MAIN_OBJECTS = main.o
game-debug: $(EXECUTABLE_MAIN)

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
clean :
	\rm  *.o *.exe *.out

%.o: src/%.cpp
	$(CC) $(INCLUDE_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c src/$*.cpp

%.out: %.o
	$(CC) $(OBJECTS) $(MAIN_OBJECTS) $(INCLUDE_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $*.out

# ========== OBJECTS ==========
#Animation.o: include/Animation.h Sprite.o
#Background.o: include/Background.h Animation.o
#Camera.o: include/Camera.h utility.o
#Character.o: include/Character.h Animation.o
#Collision.o: include/collision.hpp
#Game.o: include/Game.h SaveFile.o Window.o
#Input.o: include/Input.h
#Parallax.o: include/Parallax.h Background.o Physics.o utility.o
#Physics.o: include/Physics.h
#Player.o: include/Player.h
#SaveFile.o: include/Savefile.h
#Sprite.o: include/Sprite.h
#utility.o: include/utility.hpp
#Window.o: include/Window.h

main.o: $(OBJECTS) $(MAIN)

