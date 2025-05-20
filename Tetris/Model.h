#pragma once

#include "Text.h"
#include "Square.h"


#include <vector>
#include <string>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800

static class Model
{
public:
	static void AddText(std::string, int, int);
	static void RemoveText(int);
	static Text GetText(int);
	static int GetTextLength();
	static void AddSquare(int, int, int, int, int, int, int, int, int,int);
	static void RemoveSquare(int);
	static Square GetSquare(int);
	static int GetSquareLength();
	static void ClearVector();

private:
	static std::vector<Text> text;
	static std::vector<Square> square;
};