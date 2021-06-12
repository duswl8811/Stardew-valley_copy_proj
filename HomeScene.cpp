#include "stdafx.h"
#include "HomeScene.h"

#include "SceneManager.h"
#include "ObjectManager.h"
#include "KeyManager.h"

#include "Object.h"
#include "Player.h"

HomeScene::HomeScene()
{
}

HomeScene::~HomeScene()
{
	Release();
}

void HomeScene::Initialize()
{

}

int HomeScene::Progress()
{
	ObjectManager::GetInstance()->Progress();

	return 0;
}

void HomeScene::Render(HDC _hdc)
{
	
}

void HomeScene::Release()
{
	ObjectManager::GetInstance()->DestroyInstance();
}

void HomeScene::CheckKey()
{
	DWORD dwKey = KeyManager::GetInstance()->GetKeyState();
	if (dwKey & KEY_ESCAPE)
	{
		
	}
}