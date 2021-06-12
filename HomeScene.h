#pragma once
#include "Scene.h"
#include "Player.h"

class HomeScene : public Scene
{

public:
	HomeScene();
	~HomeScene();

	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC _hdc);
	virtual void Release();

	void CheckKey();
};

