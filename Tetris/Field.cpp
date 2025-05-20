#include "Field.h"
#include "Model.h"

void Field::Init()
{
	for (int i = 0; i < FIELD_WIDTH; i++) 
	{
		for (int j = 0; j < FIELD_HEIGHT; j++) 
		{
			field[i][j] = Block();
			field[i][j].Init(i, j, Black);
		}
	}
}

void Field::SetBlock(Position pos, Color color)
{
	field[pos.x()][pos.y()].SetColor(color);
}

Color Field::GetBlock(Position pos) 
{
	return field[pos.x()][pos.y()].GetColor();
}

void Field::DrawField() 
{
	for (int i = 0; i < FIELD_WIDTH; i++) 
	{
		for (int j = 0; j < FIELD_HEIGHT; j++)
		{
			field[i][j].DrawBlock();
		}
	}
}

bool Field::CheckLine(int height)
{
	for (int i = 0; i < FIELD_WIDTH; i++)
	{
		if (field[i][height].GetColor() == Black)
		{
			return false;
		}
	}
	return true;
}

void Field::ClearLine(int height)
{
	for (int i = height; i > 0; i--)
	{
		for (int j = 0; j < FIELD_WIDTH; j++)
		{
			field[j][i].SetColor(field[j][i - 1].GetColor());
			field[j][i - 1].SetColor(Black);
		}
	}
}

