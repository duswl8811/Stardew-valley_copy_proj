#include "stdafx.h"
#include "MainGame.h"
#include "KeyManager.h"
#include "SceneManager.h"

#ifndef _EXTERN_H_
#define _EXTERN_H_
//�߰� ���� ����
extern HWND g_hWnd;
#endif

MainGame::MainGame()
{
	AllocConsole();	//�ܼ� �Ҵ�
	FILE *acStreamOut;
	FILE *acStreamIn;
	freopen_s(&acStreamOut, "CONOUT$", "wt", stdout);
	freopen_s(&acStreamIn, "CONIN$", "r", stdin);
}


MainGame::~MainGame()
{
	Release();

	FreeConsole();   //�ܼ��� ����
}

void MainGame::Initialize()
{
	hdc = GetDC(g_hWnd);

	SceneManager::GetInstance()->Initialize();

}

void MainGame::Progress()
{
	KeyManager::GetInstance()->SetKeyState();

	SceneManager::GetInstance()->Progress();

	 InvalidateRect(g_hWnd, NULL, FALSE);
}

void MainGame::Render()
{
	hdc = BeginPaint(g_hWnd, &ps);

	//TextOut(hdc, 0, 0, _T("HelloWorld") , 10);


	SceneManager::GetInstance()->Render(hdc);

	EndPaint(g_hWnd, &ps);
}

void MainGame::Release()
{
	SceneManager::GetInstance()->DestroyInstance();

	ReleaseDC(g_hWnd, hdc);
}
