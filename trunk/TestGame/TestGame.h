#ifndef TEST_GAME_H
#define TEST_GAME_H

#include "../Engine/Engine.h"

class TestGame : public Game
{
public:

	// constructor / destructor
	TestGame (HINSTANCE hInstance);
	~TestGame ();

protected:

	// derived from Game
	bool OnStartUp();
	bool OnLoop();
	bool OnShutDown();

};
#endif