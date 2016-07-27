#ifndef LEVELTEST_H
#define LEVELTEST_H

class LevelTest : public Level {

private:
	void updateVelocityX( int objectID, float vel );
	void updateVelocityY( int objectID, float vel );
public:
	LevelTest();
	void handle_KEYDOWN( const SDL_Keycode keycode ) override;
	void handle_KEYUP( const SDL_Keycode keycode ) override;

};

#endif

