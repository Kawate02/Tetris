#include "Mino.h"

void Mino::Init(int x, int y, MinoType _type, Field* _field)
{
	field = _field;
	type = _type;
	switch (_type)
	{
	case I:
		block[0].Init(0, 0, SkyBlue);
		block[1].Init(0, 1, SkyBlue);
		block[2].Init(0, 2, SkyBlue);
		block[3].Init(0, -1, SkyBlue);
		break;
	case J:
		block[0].Init(0, 0, Blue);
		block[1].Init(0, 1, Blue);
		block[2].Init(0, -1, Blue);
		block[3].Init(-1, 1, Blue);
		break;
	case L:
		block[0].Init(0, 0, Orange);
		block[1].Init(0, 1, Orange);
		block[2].Init(0, -1, Orange);
		block[3].Init(1, 1, Orange);
		break;
	case O:
		block[0].Init(0, 0, Yellow);
		block[1].Init(0, 1, Yellow);
		block[2].Init(1, 0, Yellow);
		block[3].Init(1, 1, Yellow);
		break;
	case S:
		block[0].Init(0, 0, Green);
		block[1].Init(0, 1, Green);
		block[2].Init(1, 0, Green);
		block[3].Init(1, -1, Green);
		break;
	case T:
		block[0].Init(0, 0, Purple);
		block[1].Init(1, 0, Purple);
		block[2].Init(0, -1, Purple);
		block[3].Init(-1, 0, Purple);
		break;
	case Z:
		block[0].Init(0, 0, Red);
		block[1].Init(0, 1, Red);
		block[2].Init(-1, 0, Red);
		block[3].Init(-1, -1, Red);
		break;
	default:
		break;
	}
	for (size_t i = 0; i < 4; i++)
	{
		block[i].Move(x, y);
	}
	for (size_t i = 0; i < 4; i++)
	{
		if (!CheckBlock(block[i].pos.x(), block[i].pos.y()))
		{
			stacked = true;
		}
	}
}
bool Mino::Rotate(Direction isRight)
{
	int x[4], y[4];
	if (isRight)
	{
		for (size_t i = 0; i < 4; i++)
		{
			x[i] = block[0].pos.x() - block[i].pos.x();
			y[i] = block[0].pos.y() - block[i].pos.y();
			if (!CheckBlock(y[i] + block[0].pos.x(), -x[i] + block[0].pos.y()))
			{
				return false;
			}
		}
		for (size_t i = 0; i < 4; i++)
		{
			block[i].Set(y[i] + block[0].pos.x(), -x[i] + block[0].pos.y());
		}
	}
	if (!isRight)
	{
		for (size_t i = 0; i < 4; i++)
		{
			x[i] = block[0].pos.x() - block[i].pos.x();
			y[i] = block[0].pos.y() - block[i].pos.y();
			if (!CheckBlock(-y[i] + block[0].pos.x(), x[i] + block[0].pos.y()))
			{
				return false;
			}
		}
		for (size_t i = 0; i < 4; i++)
		{
			block[i].Set(-y[i] + block[0].pos.x(), x[i] + block[0].pos.y());
		}
	}
	return true;
}

void Mino::Draw()
{
	for (size_t i = 0; i < 4; i++)
	{
		block[i].DrawBlock();
	}
}

bool Mino::Move(int x, int y)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (!CheckBlock(x + block[i].pos.x(), y + block[i].pos.y()))
		{
			return false;
		}
	}
	
	for (size_t i = 0; i < 4; i++)
	{
		block[i].Move(x, y);
	}
	return true;
}

bool Mino::CheckBlock(int x, int y)
{
	if (field->GetBlock(Position(x, y)) != Black || x < 0 || y < 0 || x >= FIELD_WIDTH || y >= FIELD_HEIGHT)
	{
		return false;
	}
	return true;
}

bool Mino::Down()
{
	if (Move(0, 1))
	{
		return true;
	}
	for (size_t i = 0; i < 4; i++)
	{
		field->SetBlock(block[i].pos, block[i].GetColor());
	}
	for (size_t i = 0; i < FIELD_HEIGHT; i++)
	{
		if (field->CheckLine(i))
		{
			field->ClearLine(i);
		}
	}
	return false;
}

MinoType Mino::GetType()
{
	return type;
}
