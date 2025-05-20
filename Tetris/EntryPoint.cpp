#include "EntryPoint.h"

EntryPoint::EntryPoint(HWND* _hWnd, HDC* _hdc) : draw(_hdc, _hWnd), sceneManager(), input()
{

}

void EntryPoint::Start()
{
	sceneManager.SetScene(SceneNum::TITLE);
	while (true)
	{
		clock_t chkFps = clock() + CLOCKS_PER_SEC / FPS;
		if (end)
		{
			break;
		}
		Update();
	
		while (clock() < chkFps) {}
	}


}

void EntryPoint::Update()
{
	input.GetKey();
	sceneManager.SceneUpdate();
	draw.ShowDisplay();
}

bool EntryPoint::end = false;
void EntryPoint::End()
{
	end = true;
}
