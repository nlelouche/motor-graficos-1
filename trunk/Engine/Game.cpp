#include "Game.h"
#include <d3d9.h>
#include <assert.h>
//--------------------------------------------------------------------------------
Game::Game(HINSTANCE hInstance)
:
m_pkWindows(NULL),
m_pkRenderer(NULL),
m_hInstance(hInstance)
{
	
}
//--------------------------------------------------------------------------------
Game::~Game()
{
}
//--------------------------------------------------------------------------------
bool Game::StartUp()
{
	//variable temporal para almacenar el hWnd recibirlo del createWindow y 
	//pasarlo a InitDX (Al implementar Renderer)
	HWND hWnd=NULL;

	m_pkWindows = new Window(m_hInstance);

	if (!m_pkWindows)
		return false;

	m_pkWindows->createWindow(800, 600, hWnd);

	m_pkRenderer = new Renderer(hWnd);
	
	if(!m_pkRenderer)
		return false;

	if(!m_pkRenderer->InitDX(hWnd))
		return false;

	if (!OnStartUp())
		return false;

	return true;
}
//--------------------------------------------------------------------------------
bool Game::Loop()
{

	assert(m_pkRenderer);
	m_pkRenderer->StartFrame();

	m_pkRenderer->Draw();

	if (OnLoop()){
		return true;
	}

	m_pkRenderer->EndFrame();
	
	return false;

}
//--------------------------------------------------------------------------------
bool Game::ShutDown()
{
	if (!OnShutDown())
		return false;

	if (m_pkWindows)
	{
		delete m_pkWindows;
		m_pkWindows = NULL;
	}

	return true;
}
//--------------------------------------------------------------------------------
