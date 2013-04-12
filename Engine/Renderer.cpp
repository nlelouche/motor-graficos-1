#include "Renderer.h"

//--------------------------------------------------------------

Renderer::Renderer(HWND hWnd)
	:
m_hWnd(NULL),
	m_pkDevice(NULL)
{
}
//--------------------------------------------------------------
Renderer::~Renderer(){
	if (m_hWnd){
		delete m_hWnd;
		m_hWnd = NULL;
	}
	if (m_pkDevice){
		m_pkDevice->Release();
		m_pkDevice = NULL;
	}
}
//--------------------------------------------------------------
bool Renderer::InitDX(HWND hWnd){


	IDirect3D9 * _pD3D;

	// Intento crear el objeto DX9
	_pD3D = Direct3DCreate9(D3D_SDK_VERSION);	

	if (!_pD3D)
		return false;

	//guardo la resolución actual del escritorio
	D3DDISPLAYMODE displayMode;
	HRESULT hr = _pD3D->GetAdapterDisplayMode (
		D3DADAPTER_DEFAULT,
		&displayMode
		);

	if (hr!=D3D_OK)
		return false;

	// Fijo los valores a la estructura D3DPRESENT_PARAMETERS
	D3DPRESENT_PARAMETERS d3dPresentParameters;
	ZeroMemory( &d3dPresentParameters, sizeof(d3dPresentParameters));
	d3dPresentParameters.BackBufferFormat = displayMode.Format;
	d3dPresentParameters.Windowed = true;
	d3dPresentParameters.BackBufferCount = 1; 
	d3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dPresentParameters.hDeviceWindow = 0; 
	d3dPresentParameters.Flags = 0;
	d3dPresentParameters.EnableAutoDepthStencil = TRUE;
	d3dPresentParameters.AutoDepthStencilFormat = D3DFMT_D24S8; d3dPresentParameters.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dPresentParameters.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	//invocaremos al método CreateDevice
	hr = _pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dPresentParameters,
		&m_pkDevice
		);

	if (hr!=D3D_OK)
	{
		hr = _pD3D->CreateDevice(
			D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dPresentParameters,
			&m_pkDevice
			);
	}

	if (hr!=D3D_OK)
		return false;

	if (!m_pkDevice)
		return false;

	m_pkDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	m_pkDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	m_pkDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	m_pkDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	//m_pkDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	m_pkDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
	m_pkDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

	//---------------------------------------------------------------------------------------

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



	if(FAILED(m_pkDevice->CreateVertexBuffer(3*sizeof(D3DVERTEX), 0, 
		D3DFVF_XYZRHW|D3DFVF_DIFFUSE, D3DPOOL_DEFAULT, &pVertexObject, NULL)))
		return(0);

	if(FAILED(pVertexObject->Lock(0, 3*sizeof(D3DVERTEX), &pVertexBuffer, 0)))
		return(0);

	memcpy(pVertexBuffer, vertices, 3*sizeof(D3DVERTEX));
	pVertexObject->Unlock();

	//---------------------------------------------------------------------------------------
	if (hr!=D3D_OK)
		return false;

	return true;
}
//--------------------------------------------------------------
void Renderer::Draw(/*ColorVertex * vertexColletion, PrimitiveType ePrim, unsigned int uiVertexCount*/){

	m_pkDevice->SetStreamSource(0, pVertexObject, 0, sizeof(D3DVERTEX));
	m_pkDevice->SetFVF(D3DFVF_XYZRHW|D3DFVF_DIFFUSE);
	m_pkDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
}
//--------------------------------------------------------------
void Renderer::setMatrixMode (MatrixMode eMode){
}
//--------------------------------------------------------------
void Renderer::loadIdentity (){
}
//--------------------------------------------------------------
void Renderer::translate (float fX, float fY, float fZ){
}
//--------------------------------------------------------------
void Renderer::rotateX (float fAngle){
}
//--------------------------------------------------------------
void Renderer::rotateY (float fAngle){
}
//--------------------------------------------------------------
void Renderer::rotateZ (float fAngle){
}
//--------------------------------------------------------------
void Renderer::scale (float fW, float fH){
}
//----------------------------------------------------------------
void Renderer::StartFrame(){

	// Limpia la escena
	m_pkDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 150, 150), 1.0f, 0);

	// Comienzo el render de una escena
	m_pkDevice->BeginScene();

}
//--------------------------------------------------------------
void Renderer::EndFrame(){
	// Termina el render de una escena
	m_pkDevice->EndScene();

	//Present
	m_pkDevice->Present(NULL, NULL, NULL, NULL);
}
//--------------------------------------------------------------