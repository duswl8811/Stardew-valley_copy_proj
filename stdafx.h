// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <math.h>
#include <tchar.h>
#include <iostream>
#include <map>
#include <list>

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.

#pragma comment (lib, "Msimg32.lib")

#define WINDOW_SIZE_X 1200
#define	WINDOW_SIZE_Y 800
#define PLAYER_WINDOW_POS_X WINDOW_SIZE_X/2
#define PLAYER_WINDOW_POS_Y WINDOW_SIZE_Y/2
#define MAP_SIZE_X 00
#define MAP_SIZE_Y 00
#define	MAP_MIN_POS_X (WINDOW_MAX_SIZE_X - MAP_SIZE_X)
#define MAP_MAX_POS_X 00
#define	MAP_MIN_POS_Y (WINDOW_MAX_SIZE_Y - MAP_SIZE_Y)
#define MAP_MAX_POS_Y 00

#define SIZE	20

// DIRECTION
#define LEFT	-1
#define TOP		2
#define UP		2
#define BACK	2
#define RIGHT	1
#define BOTTOM	0
#define DOWN	0
#define FRONT	0

// PLAYER STATE
#define IDEL	201
#define WALK	202
#define RUN		203

//unsigned long
const DWORD KEY_LEFT = 0x00000001;
const DWORD KEY_RIGHT = 0x00000002;
const DWORD KEY_UP = 0x00000010;
const DWORD KEY_DOWN = 0x00000020;

const DWORD KEY_A = 0x00000001;
const DWORD KEY_D = 0x00000002;
const DWORD KEY_W = 0x00000010;
const DWORD KEY_S = 0x00000020;

const DWORD KEY_ENTER = 0x00000100;
const DWORD KEY_ESCAPE = 0x00001000;
const DWORD KEY_C = 0x00010000;
const DWORD KEY_X = 0x00020000;

typedef struct position { int x; int y; };

// OBJ
// PLAYER
// ITEM
// INVENTORY ( NEED INVENTORY WORK PLAN )
// NPC
// MONSTER
// MAP

struct CRECT
{
	position pos;
	int size = 15;
	int xsize;
	int ysize;
	int l;
	int t;
	int r;
	int b;

	void SetPos(position p) { pos = p; };
	void SetPos(int _x, int _y) { pos.x = _x; pos.y = _y; };

	void SetRectFromCurrentPos()
	{
		l = pos.x - size;
		t = pos.y - size;
		r = pos.x + size;
		b = pos.y + size;
	}
};
