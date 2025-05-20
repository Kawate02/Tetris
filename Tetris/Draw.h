#pragma once

#include "resource.h"
#include "framework.h"
#include "Model.h"

#include <tchar.h>

class Draw
{
public:
	Draw(HDC* _hdc, HWND* _hWnd) : hdc(_hdc), hWnd(_hWnd) {};
	void ShowDisplay();
private:
	void DrawSquea(int, int, int, int, COLORREF, COLORREF);
	HDC* hdc;
	HWND* hWnd;
};