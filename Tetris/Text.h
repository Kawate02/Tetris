#pragma once

#include <string>
class Text
{
public:
	Text(std::string text, int x, int y) : text(text), x(x), y(y) {};
	std::string text;
	int x;
	int y;
};