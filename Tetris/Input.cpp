#include "Input.h"
#include "Model.h"

BYTE Input::old_key[256] = { 0 };
BYTE Input::key[256] = { 0 };

void Input::GetKey()
{
	for (int i = 0; i < 256; i++)
	{
		old_key[i] = key[i];
	}
	for (int i = 0; i < 256; i++)
	{
		if (GetKeyState(i) & 0x80)
		{
			key[i] = 0x80;
		}
		else
		{
			key[i] = 0x00;
		}
	}
}

bool Input::Key(int num)
{
	if (key[num] & 0x80 && old_key[num] & 0x80)
	{
		return true;
	}
	return false;
}

bool Input::KeyDown(int num)
{
	if (key[num] & 0x80 && !(old_key[num] & 0x80))
	{
		return true;
	}
	return false;
}
