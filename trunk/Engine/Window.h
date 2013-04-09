#ifndef WINDOW_H
#define WINDOW_H
//--------------------------------------------------------------------------------
#include "Defines.h"
//--------------------------------------------------------------------------------
class ENGINE_API Window
{

public:

	Window(HINSTANCE hInstance);
	~Window();

	bool createWindow(unsigned int uiWidth, unsigned int uiHeight, HWND & hWnd);
	void SetWindowTitle(LPCSTR lpString);

private:

	// cosas de Windows
	HWND m_hWnd;
	HINSTANCE m_hInstance;

};
//--------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
//--------------------------------------------------------------------------------
#endif //WINDOW_H