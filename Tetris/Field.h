#pragma once

#include "Block.h"

class Field {
public:
	void Init();
	void SetBlock(Position, Color);
	Color GetBlock(Position);
	void DrawField();

	bool CheckLine(int);
	void ClearLine(int);
private:
	Block field[FIELD_WIDTH][FIELD_HEIGHT];
};