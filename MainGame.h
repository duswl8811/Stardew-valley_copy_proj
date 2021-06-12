#pragma once
class MainGame
{
	HDC hdc;
	PAINTSTRUCT ps;

public:
	MainGame();
	~MainGame();

	void Initialize();
	void Progress();
	void Render();
	void Release();
};

