#include "Game.h"
#include <d3d9.h>
LPDIRECT3D9       g_pDirect3D = NULL;
LPDIRECT3DDEVICE9 g_pDirect3D_Device = NULL;
//--------------------------------------------------------------------------------
Game::Game(HINSTANCE hInstance)
:
m_pkWindows(NULL),
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

	//----------------------------------------------------------
	// Inicializar DX

	g_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS PresentParams;
	memset(&PresentParams, 0, sizeof(D3DPRESENT_PARAMETERS));

	PresentParams.Windowed = TRUE;
	PresentParams.SwapEffect = D3DSWAPEFFECT_DISCARD;

	g_pDirect3D->CreateDevice(D3DADAPTER_DEFAULT,
								D3DDEVTYPE_HAL,
								hWnd,
								D3DCREATE_SOFTWARE_VERTEXPROCESSING,
								&PresentParams,
								&g_pDirect3D_Device);

//----------------------------------------------------------
/*

	struct D3DVERTEX {float x, y, z, rhw; DWORD color;} vertices[3];

 

  vertices[0].x = 50; 
  vertices[0].y = 50; 
  vertices[0].z = 0; 
  vertices[0].rhw = 1.0f; 
  vertices[0].color = 0x00ff00;

 

  vertices[1].x = 250; 
  vertices[1].y = 50; 
  vertices[1].z = 0; 
  vertices[1].rhw = 1.0f; 
  vertices[1].color = 0x0000ff;

 

  vertices[2].x = 50; 
  vertices[2].y = 250; 
  vertices[2].z = 0; 
  vertices[2].rhw = 1.0f;
  vertices[2].color = 0xff0000;


  pVertexObject = NULL;
	pVertexBuffer = NULL;

 

if(FAILED(g_pDirect3D_Device->CreateVertexBuffer(3*sizeof(D3DVERTEX), 0, 
          D3DFVF_XYZRHW|D3DFVF_DIFFUSE, D3DPOOL_DEFAULT, &pVertexObject, NULL)))
   return(0);

if(FAILED(pVertexObject->Lock(0, 3*sizeof(D3DVERTEX), &pVertexBuffer, 0)))
   return(0);

memcpy(pVertexBuffer, vertices, 3*sizeof(D3DVERTEX));
pVertexObject->Unlock();
*/
//----------------------------------------------------------


	if (!OnStartUp())
		return false;

	return true;
}
//--------------------------------------------------------------------------------
bool Game::Loop()
{
	g_pDirect3D_Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255),

                          1.0f, 0);

/*
if(SUCCEEDED(g_pDirect3D_Device->BeginScene()))
{
   g_pDirect3D_Device->SetStreamSource(0, pVertexObject, 0, sizeof(D3DVERTEX));
   g_pDirect3D_Device->SetFVF(D3DFVF_XYZRHW|D3DFVF_DIFFUSE);
   g_pDirect3D_Device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
   g_pDirect3D_Device->EndScene();
}
*/

	g_pDirect3D_Device->Present(NULL, NULL, NULL, NULL);




 

//ValidateRect(hW, NULL);

	if (OnLoop())
		return true;

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

	if(g_pDirect3D_Device != NULL)
	{
		g_pDirect3D_Device->Release();
		g_pDirect3D_Device = NULL;
	}

	if(g_pDirect3D != NULL)
	{
		 g_pDirect3D->Release();
		 g_pDirect3D = NULL;
	}

	//pVertexObject->Release();

	return true;
}
//--------------------------------------------------------------------------------
