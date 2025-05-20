#pragma once

#include "framework.h"

class Square
{
public:
	Square(int _left, int _top, int _right, int _bottom, COLORREF _penColor, COLORREF _brushColor) : left(_left), top(_top), right(_right), bottom(_bottom), penColor(_penColor), brushColor(_brushColor) {};
	int left, top, right, bottom;
	COLORREF penColor, brushColor;
};