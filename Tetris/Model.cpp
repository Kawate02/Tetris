#include "Model.h"

std::vector<Text> Model::text = std::vector<Text>();
std::vector<Square> Model::square = std::vector<Square>();

void Model::AddText(std::string _text, int _x, int _y)
{
	text.push_back(Text(_text, _x, _y));
}
void Model::RemoveText(int index)
{
	text.erase(text.begin() + index);
}

Text Model::GetText(int index)
{
	return text[index];
}

int Model::GetTextLength()
{
	return text.size();
}

void Model::AddSquare(int left, int top, int right, int bottom, int pr, int pg, int pb, int br, int bg, int bb)
{
	COLORREF penColor = RGB(pr, pg, pb);
	COLORREF brushColor = RGB(br, bg, bb);
	square.push_back(Square(left, top, right, bottom, penColor, brushColor));
}

void Model::RemoveSquare(int index)
{
	square.erase(square.begin() + index);
}

Square Model::GetSquare(int index)
{
	return square[index];
}

int Model::GetSquareLength()
{
	return square.size();
}

void Model::ClearVector()
{
	text.clear();
	square.clear();
}

