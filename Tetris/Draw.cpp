#include "Draw.h"

int _count = 0;
void Draw::ShowDisplay()
{

	_count++;
	Model::AddText("Draw called count:" + std::to_string(_count), 0, 80);
	DrawSquea(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, RGB(255, 255, 255), RGB(255, 255, 255));
	for (int i = 0; i < Model::GetSquareLength(); i++)
	{
		Square square = Model::GetSquare(i);
		DrawSquea(square.left, square.top, square.right, square.bottom, square.brushColor, square.penColor);
	}
	for (int i = 0; i < Model::GetTextLength(); i++)
	{
		Text text = Model::GetText(i);
		TextOutA(*hdc, text.x, text.y, text.text.c_str(), strlen(text.text.c_str()));
	}
	Model::ClearVector();
	InvalidateRect(*hWnd, NULL, false);
	UpdateWindow(*hWnd);
}

void Draw::DrawSquea(int left, int top, int right, int bottom, COLORREF brushColor, COLORREF penColor)
{
	HPEN pen = CreatePen(PS_SOLID, 0, penColor);
	HBRUSH brush = CreateSolidBrush(brushColor);
	SelectObject(*hdc, pen);
	Rectangle(*hdc, left, top, right, bottom);
	SelectObject(*hdc, brush);
	Rectangle(*hdc, left, top, right, bottom);
	DeleteObject(pen);
	DeleteObject(brush);
}
