#pragma once

#include "SceneBase.h"

class Game : public SceneBase
{
public:
	virtual void OnStart();
	virtual void OnUpdate();
private:
	void NextMino();
};