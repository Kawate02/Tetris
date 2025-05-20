#pragma once
#include "Position.h"
#include "Model.h"

#define FIELD_WIDTH 10
#define FIELD_HEIGHT 15
#define SQUARE_SIZE 30
#define WIDTH_CENTER  WINDOW_WIDTH / 2 - SQUARE_SIZE * FIELD_WIDTH / 2
#define HEIGHT_CENTER WINDOW_HEIGHT - SQUARE_SIZE * (FIELD_HEIGHT + 2)

#define BLACK r = 10; g = 10; b = 10;
#define SKY_BLUE r = 10; g = 200; b = 200;
#define YELLOW r = 200; g = 200; b = 10;
#define PURPLE r = 200; g = 10; b = 200;
#define BLUE r = 10; g = 10; b = 200;
#define ORANGE r = 200; g = 127; b = 10;
#define GREEN r = 10; g = 200; b = 10;
#define RED r = 200; g = 10; b = 10;

enum Color 
{
	Black = 0,
	SkyBlue = 1,
	Yellow,
	Purple,
	Blue,
	Orange,
	Green,
	Red
};

class Block 
{
public:
	void Init(int _x, int _y, Color _color);
	void DrawBlock();
	void Move(int, int);
	void Set(int, int);
	void SetColor(Color);
	Color GetColor();
	Position pos;
private:
	Color color;
};