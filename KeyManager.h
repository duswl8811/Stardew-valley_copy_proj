#pragma once



class KeyManager
{
private:
	// 정적 멤버란 클래스에는 속하지만, 객체 별로 할당되지 않고 클래스의 모든 객체가 공유하는 멤버를 의미합니다.
	static KeyManager* instance;

public:
	static KeyManager* GetInstance() {
		if (instance == NULL)
			instance = new KeyManager;

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
	DWORD key; // wParam // dword? // wordParam 이라서 dword 사용
	KeyManager(); // 외부에서 생성을 막기 위해

public:
	~KeyManager();

	void SetKeyState();
	DWORD GetKeyState();


};

