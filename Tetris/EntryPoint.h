#pragma once

#define FPS 60
#include "framework.h"

#include "SceneManager.h"
#include "Draw.h"
#include "Input.h"

#include <time.h>

class EntryPoint
{
public:
	EntryPoint(HWND*, HDC*);
	void Start();
	void Update();
	static void End();

private:
	static bool end;
	Input input;
	SceneManager sceneManager;
	Draw draw;
};