#ifndef RENDERER_H
#define RENDERER_H
//-----------------------------------------------------------
//Includes:
#include <D3D9.h>
#include <D3DX9.h>
#include "Defines.h"
#include "Structs.h"
//-----------------------------------------------------------

class ENGINE_API Renderer {

	Renderer(HWND hWnd);
	~Renderer();

public:
	void Draw(/*ColorVertex * vertexColletion, PrimitiveType ePrim, unsigned int uiVertexCount*/);

	// matrix handling
	void setMatrixMode (MatrixMode eMode);
	void loadIdentity ();
	void translate (float fX, float fY, float fZ = 0.0f);
	void rotateX (float fAngle);
	void rotateY (float fAngle);
	void rotateZ (float fAngle);
	void scale (float fW, float fH);

private:
	void StartFrame();
	void EndFrame();
	bool InitDX(HWND hWnd);

	HWND m_hWnd;
	IDirect3DDevice9*  m_pkDevice;
	friend class Game;


 // Triangle
struct D3DVERTEX
{
   float x, y, z, rhw;
   DWORD color;
};
	void *pVertexBuffer;// = NULL;
	LPDIRECT3DVERTEXBUFFER9 pVertexObject;


};
#endif RENDERER_H