#include "stdafx.h"
#include "LogoScene.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Player.h"

LogoScene::LogoScene()
{
}

LogoScene::~LogoScene()
{
	Release();
}

void LogoScene::Initialize()
{
	player = new Player();
	player->Initialize();

	backgroundBit = (HBITMAP)LoadImage(NULL, "background.bmp", IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	GetObject(backgroundBit, sizeof(BITMAP), &backgroundBmp);
}

int LogoScene::Progress()
{
	ObjectManager::GetInstance()->Progress();
	player->Progress();


	return 0;
}

void LogoScene::Render(HDC _hdc)
{
	//SceneManager::GetInstance()->ChangeScene(HOMEscene, 0);
	memdc = CreateCompatibleDC(_hdc);
	StretchBit = CreateCompatibleBitmap(_hdc, WINDOW_SIZE_X, WINDOW_SIZE_Y);
	oldBit = (HBITMAP)SelectObject(memdc, StretchBit);

	source_dc = CreateCompatibleDC(memdc);
	oldBit2 = (HBITMAP)SelectObject(source_dc, backgroundBit); // char_sheet

	//BitBlt(memdc, 0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y, source_dc, 0, 0, SRCCOPY);
	TransparentBlt(memdc, 0, 0, backgroundBmp.bmWidth/2, backgroundBmp.bmHeight/2,
		source_dc, 0, 0, backgroundBmp.bmWidth, backgroundBmp.bmHeight, RGB(255, 255, 255));
	player->Render(memdc);
	BitBlt(_hdc, 0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y, memdc, 0, 0, SRCCOPY);
	//SelectObject(memdc, oldBit);

	SelectObject(source_dc, oldBit2);
	SelectObject(memdc, oldBit);

}

void LogoScene::Release()
{
	DeleteObject(hBit);
	DeleteObject(StretchBit);
	DeleteObject(backgroundBit);
	DeleteDC(memdc);
	DeleteDC(source_dc);

	ObjectManager::GetInstance()->DestroyInstance();
}
