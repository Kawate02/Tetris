#include "Game.h"
#include "Field.h"
#include "MinoManager.h"

Field field;
MinoManager minoManager;
Mino crrentMino;

int count = 0;
void Game::OnStart()
{
	field.Init();
	minoManager.Init(&field);
	crrentMino.stacked = false;
	NextMino();
}

void Game::OnUpdate()
{
	if (crrentMino.stacked)
	{
		if (Input::KeyDown(Input::fix))
		{
			OnStart();
		}
		field.DrawField();
		crrentMino.Draw();
		return;
	}
	count++;
	if (Input::KeyDown(Input::right_move))
	{
		crrentMino.Move(1, 0);
	}
	if (Input::KeyDown(Input::left_move))
	{
		crrentMino.Move(-1, 0);
	}
	if (Input::KeyDown(Input::down_move))
	{
		if (!crrentMino.Down())
		{
			NextMino();
		}
		
	}
	if (Input::KeyDown(Input::fall))
	{
		while (crrentMino.Down()){}
		NextMino();
	}
	if (Input::KeyDown(Input::right_rotate))
	{
		crrentMino.Rotate(Right);
	}
	if (Input::KeyDown(Input::left_rotate))
	{
		crrentMino.Rotate(Left);
	}

	if (count % 60 == 0)
	{
		if (!crrentMino.Down())
		{
			NextMino();
		}
	}

	field.DrawField();
	crrentMino.Draw();
}

void Game::NextMino()
{
	crrentMino.Init(5, 1, minoManager.NextMino(), &field);
}
