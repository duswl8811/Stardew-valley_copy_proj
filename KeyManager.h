#pragma once



class KeyManager
{
private:
	// ���� ����� Ŭ�������� ��������, ��ü ���� �Ҵ���� �ʰ� Ŭ������ ��� ��ü�� �����ϴ� ����� �ǹ��մϴ�.
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
	DWORD key; // wParam // dword? // wordParam �̶� dword ���
	KeyManager(); // �ܺο��� ������ ���� ����

public:
	~KeyManager();

	void SetKeyState();
	DWORD GetKeyState();


};

