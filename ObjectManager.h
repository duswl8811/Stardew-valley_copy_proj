#pragma once

class Object;

class ObjectManager
{
	static ObjectManager*	instance;
	std::list<Object*>		object_list[1];
	class Player*			player;

public:
	static ObjectManager* GetInstance() {
		if (instance == NULL)
			instance = new ObjectManager;

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
	ObjectManager();
public:
	~ObjectManager();

	void Initialize();
	void Progress();
	void Render();
	void Release();
};
