#pragma once

enum SceneType { TESTscene, HOMEscene };

class Scene;

class SceneManager
{
	static SceneManager*	instance;

	Scene*					scene;
	SceneType				scene_type;
	bool					change_scene;

public:
	static SceneManager* GetInstance() {
		if (instance == NULL)
			instance = new SceneManager;

		return instance;
	}

	static void DestroyInstance() {
		if (instance != NULL)
		{
			delete instance;
			instance = NULL;
		}
	}

private:
	SceneManager();
public:
	~SceneManager();

	void Initialize();
	void Progress();
	void Render(HDC _hdc);
	void Release();

	void SetScene(SceneType st);
	void ChangeScene(SceneType st, int scene_Info = 0);
};

