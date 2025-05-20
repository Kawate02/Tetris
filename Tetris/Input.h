#pragma once

#include "framework.h"
#include <vector>

class Input
{
public:
	static const int left_move = 0x25;
	static const int right_move = 0x27;
	static const int left_rotate = 0x41;
	static const int right_rotate = 0x44;
	static const int down_move = 0x28;
	static const int fall = 0x26;
	static const int hold = 0xA0;
	static const int fix = 0x20;
	static const int escape = 0x1B;
	static bool Key(int);
	static bool KeyDown(int);
	void GetKey();
	static BYTE old_key[256];
	static BYTE key[256];

private:
	
};