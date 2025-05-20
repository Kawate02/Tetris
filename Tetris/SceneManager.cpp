#include "SceneManager.h"
#include "EntryPoint.h"


SceneManager::SceneManager() : crrentScene(), title(Title()), game(Game())
{}

void SceneManager::SetScene(SceneNum index)
{
	switch (index)
	{
	case TITLE:
		crrentScene = &title;
		break;
	case GAME:
		crrentScene = &game;
		break;
	default:
		crrentScene = &title;
		break;
	}
	crrentScene->OnStart();
}

void SceneManager::SceneUpdate()
{
	if (crrentScene == &title && Input::KeyDown(Input::fix))
	{
		SetScene(GAME);
	}
	if (crrentScene == &game && Input::KeyDown(Input::escape))
	{
		SetScene(TITLE);
	}
	crrentScene->OnUpdate();
}