#ifndef GAME_H
#define GAME_H
//--------------------------------------------------------------------------------
#include "Defines.h"
#include "Window.h"
#include <D3D9.h>
#include <D3DX9.h>
#include "Renderer.h"
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------

class ENGINE_API Game
{

public:
	Game(HINSTANCE hInstance);
	virtual ~Game();

	//engine functions
	bool StartUp();
	bool Loop();
	bool ShutDown();

protected:
	//game virtual functions to be overloaded in game
	virtual bool OnStartUp()=0;
	virtual bool OnLoop()=0;
	virtual bool OnShutDown()=0;
	Renderer* m_pkRenderer;

private:
	Window* m_pkWindows;
	HINSTANCE m_hInstance;
	
};
//--------------------------------------------------------------------------------
#endif //GAME_H 