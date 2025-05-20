#pragma once

#include "Block.h"
#include "Field.h"

enum Direction
{
	Left = 0,
	Right = 1
};
enum MinoType
{
	I = 0,
	J = 1,
	L = 2,
	O = 3,
	S = 4,
	T = 5,
	Z = 6
};

class Mino
{
public:
	void Init(int, int, MinoType, Field*);
	bool Rotate(Direction);
	void Draw();
	bool Move(int, int);
	bool CheckBlock(int, int);
	bool Down();
	bool stacked = false;
	MinoType GetType();
protected:
	Field* field;
	Block block[4];
	MinoType type;
};