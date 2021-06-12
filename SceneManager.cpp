#include "stdafx.h"
#include "SceneManager.h"
#include "Scene.h"
#include "LogoScene.h"
#include "HomeScene.h"

SceneManager*	SceneManager::instance = NULL;

SceneManager::SceneManager() 
	: scene(NULL)
	, scene_type(TESTscene)
	, change_scene(false)
{

}

SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::Initialize()
{
	SetScene(TESTscene);
}

void SceneManager::Progress()
{
	if (change_scene)
	{
		change_scene = false;
		SetScene(scene_type);
	}

	if (scene)
	{
		if (scene->Progress() == 1)
		{
			//만약에 1로 들어오면 처리
			ChangeScene(TESTscene);
		}

	}
}

void SceneManager::Render(HDC _hdc)
{
	if (scene)
		scene->Render(_hdc);
}

void SceneManager::Release()
{

}

void SceneManager::SetScene(SceneType st)
{
	if (scene)
	{
		delete scene;
		scene = NULL;
	}

	switch (st)
	{
	case TESTscene:
		scene = new LogoScene;
		break;

	case HOMEscene:
		scene = new HomeScene;
		break;
	}

	scene->Initialize();
}

void SceneManager::ChangeScene(SceneType st, int scene_Info/* = 0*/)
{
	scene_type = st;
	change_scene = true;
}