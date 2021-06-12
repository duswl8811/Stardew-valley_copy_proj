#include "stdafx.h"
#include "KeyManager.h"

KeyManager* KeyManager::instance = NULL;

KeyManager::KeyManager() : key(0)
{
}


KeyManager::~KeyManager()
{
}

void KeyManager::SetKeyState(void)
{
	key = 0;


	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
	{
		key |= KEY_RIGHT;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
	{
		key |= KEY_LEFT;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8001)
	{
		key |= KEY_UP;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8001)
	{
		key |= KEY_DOWN;
	}

	if (GetAsyncKeyState('W') & 0x8001)
	{
		key |= KEY_W;
	}

	if (GetAsyncKeyState('A') & 0x8001)
	{
		key |= KEY_A;

	}

	if (GetAsyncKeyState('S') & 0x8001)
	{
		key |= KEY_S;
	}

	if (GetAsyncKeyState('D') & 0x8001)
	{
		key |= KEY_D;
	}

	if (GetAsyncKeyState(VK_RETURN) & 0x8001)
	{
		key |= KEY_ENTER;
	}

	if (GetAsyncKeyState(VK_ESCAPE) & 0x1)
	{
		key |= KEY_ESCAPE;
	}

	if (GetAsyncKeyState('C') & 0x8001)
	{
		key |= KEY_C;
	}

	if (GetAsyncKeyState('X') & 0x8001)
	{
		key |= KEY_X;
	}


	//std::cout << key << std::endl;
}

DWORD KeyManager::GetKeyState(void)
{
	return key;
}