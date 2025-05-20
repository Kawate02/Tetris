#include "MinoManager.h"

#include <random>

void MinoManager::Init(Field* _field)
{
	field = _field;
	for (size_t i = 0; i < 8; i++)
	{
		CreateMino(i);
	}
}
MinoType MinoManager::NextMino()
{
    MinoType nextMino = mino[0];
	for (size_t i = 0; i < 7; i++)
	{
		mino[i] = mino[i + 1];
	}
	CreateMino(7);
    return nextMino;
}

void MinoManager::CreateMino(int index)
{
	int random = CreateRandom();

	if (index >= 0)
	{
		while (mino[index - 1] == random)
		{
			random = CreateRandom();
		}
	}
	mino[index] = (MinoType)random;
}

MinoType MinoManager::CreateRandom()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<> rand(0, 6);
	
	return (MinoType)rand(mt);
}
