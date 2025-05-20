#pragma once

#include "Title.h"
#include "Game.h"
#include "Model.h"

enum SceneNum
{
	TITLE = 0,
	GAME = 1,
	RESULT = 2
};

class SceneManager
{
public:
	SceneManager();
	void SetScene(SceneNum);
	void SceneUpdate();
private:
	SceneBase* crrentScene;
	Title title;
	Game game;
};