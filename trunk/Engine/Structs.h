#ifndef STRUCTS_H
#define STRUCTS_H
//----------------------------------------------------------------
#include <windows.h>
//----------------------------------------------------------------
// color vertex D3D define
#define COLOR_VERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)

// color vertex struct
struct ColorVertex
{
	float x,y,z;
	DWORD color;
};
//----------------------------------------------------------------
// include DirectX to have the matrix constants
#include <d3dx9.h>
//----------------------------------------------------------------
// matrix modes
enum MatrixMode
{
	WORLD = D3DTS_WORLDMATRIX(0),
	VIEW = D3DTS_VIEW,
	PROJECTION = D3DTS_PROJECTION
};
//----------------------------------------------------------------
enum PrimitiveType
{
	TRIANGLE_LIST = D3DPT_TRIANGLELIST,
	TRIANGLE_STRIP = D3DPT_TRIANGLESTRIP,
	TRIANGLE_FAN = D3DPT_TRIANGLEFAN,
	LINE_STRIP = D3DPT_LINESTRIP
};
//----------------------------------------------------------------
// texture vertex D3D define
#define TEXTURE_VERTEX (D3DFVF_XYZ|D3DFVF_TEX1|D3DFVF_TEXCOORDSIZE2(0))

// texture vertex struct
struct TextureVertex
{
	float X,Y,Z;
	float U, V;
};
//----------------------------------------------------------------
// Estructura para almacenar un color RGB
struct RGBColor {
	int iRed;
	int iGreen;
	int iBlue;

	RGBColor(int iR, int iG, int iB)
	{
		iRed = iR;
		iGreen = iG;
		iBlue = iB;
	}
};
//----------------------------------------------------------------
// Estructura para almacenar los datos de los caracteres de los fnt
struct CharData
{
	char cId;
	int iX;
	int iY;
	int iHeight;
	int iWidth;
	int iXOffset;
	int iYOffset;
	int iXAdvance;
};
//----------------------------------------------------------------
#endif // GRAPHICS_STRUCTS_H
//----------------------------------------------------------------