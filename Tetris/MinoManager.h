#pragma once

#include "Mino.h"

class MinoManager
{
public:
	void Init(Field*);
	MinoType NextMino();
	void CreateMino(int);
	MinoType CreateRandom();

private:
	MinoType mino[8];
	Field* field;
};