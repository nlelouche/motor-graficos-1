#ifndef GAME_H
#define GAME_H
//--------------------------------------------------------------------------------
#include "Defines.h"
#include "Window.h"
#include <d3d9.h>
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

private:
	Window* m_pkWindows;
	HINSTANCE m_hInstance;

/* // Triangle
struct D3DVERTEX
{
   float x, y, z, rhw;
   DWORD color;
};
	void *pVertexBuffer;// = NULL;
	LPDIRECT3DVERTEXBUFFER9 pVertexObject;
*/
};
//--------------------------------------------------------------------------------
#endif //GAME_H 