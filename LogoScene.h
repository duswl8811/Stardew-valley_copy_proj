#pragma once
#include "Scene.h"

class LogoScene : public Scene
{
	class Player*		player;

	HDC memdc, source_dc;
	HBITMAP oldBit, oldBit2, hBit, StretchBit, backgroundBit;
	BITMAP	backgroundBmp;
public:
	LogoScene();
	virtual ~LogoScene();

	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC _hdc);
	virtual void Release();
};

