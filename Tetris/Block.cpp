#include "Block.h"

void Block::Init(int _x, int _y, Color _color)
{
	pos.Set(_x, _y);
	color = _color;
}
void Block::DrawBlock()
{
	int x = pos.x(), y = pos.y();
	int r, g, b;
	switch (color)
	{
	case 1:
		SKY_BLUE
			break;
	case 2:
		YELLOW
			break;
	case 3:
		PURPLE
			break;
	case 4:
		BLUE
			break;
	case 5:
		ORANGE
			break;
	case 6:
		GREEN
			break;
	case 7:
		RED
			break;
	default:
		BLACK
			break;
	}
	Model::AddSquare( x * SQUARE_SIZE + WIDTH_CENTER, y * SQUARE_SIZE + HEIGHT_CENTER, x * SQUARE_SIZE + SQUARE_SIZE + WIDTH_CENTER, y * SQUARE_SIZE + SQUARE_SIZE + HEIGHT_CENTER, 200, 200, 200, r, g, b );
}

void Block::Move( int x, int y) 
{
	pos.Set( pos.x() + x, pos.y() + y );
}

void Block::Set(int x, int y)
{
	pos.Set(x, y);
}
void Block::SetColor( Color _color) 
{
	color = _color;
}

Color Block::GetColor( ) 
{
	return color;
}