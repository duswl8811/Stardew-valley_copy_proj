#pragma once
#include "Object.h"

typedef struct Size {
	int width; int height;
};

typedef struct PlayerInfo
{
	position pos = { 0,0 };
	int state = IDEL;
	int direction = FRONT;
	int energe = 255;
	int animation_num = 0;
	int animation_count = 0;
	int move_speed = 3 * 3;

	int hair_x = 2;
	int hair_y = 3;
};


class Player : public Object
{

	PlayerInfo player_info;

	HDC memdc, source_dc, edit_dc; // memdc :: back_buffer
	HBITMAP hBit, hBit2, StretchBit, oldBit, oldBit2, oldBit3, playerBit, hairBit;
	BITMAP playerBmp, hairBmp;

	Size size = { 16, 32 };

public:
	Player();
	virtual ~Player();

	bool Initialize();
	void Progress();
	void Render(HDC _hdc);
	void Release();

	void KeyCheck();

	//testing code
	void SetPos(position p) { player_info.pos = p; };
	void SetPos(int _x, int _y) { player_info.pos.x = _x; player_info.pos.y = _y; };

	Size GetCSize() { return size; };
	int GetAniNum() { return player_info.animation_num; };
	int GetDirection() { return player_info.direction; };
	position GetPos() { return player_info.pos; };

	int GetState() { return player_info.state; };
	int GetAniCount() { return player_info.animation_count; };

	void SetState(int st) { player_info.state = st; }
	void SetAniNum(int num) { player_info.animation_num = num; }
	void SetAniCount(int c) {
		player_info.animation_count = c;
		switch (player_info.animation_count)
		{
		case 0:
			player_info.animation_num = 0;
			break;

		case 1:
			player_info.animation_num = 1;
			break;

		case 2:
			player_info.animation_num = 0;
			break;

		case 3:
			player_info.animation_num = 2;
			break;

		default:
			player_info.animation_num = 0;
			break;
		}

	}
	void SetDirection(int dr)
	{
		player_info.direction = dr;

		// 왼쪽 : -1
		// 오른쪽 : 1
		// 앞 : 0
		// 뒤 : 2

		// dr을 한가지 방향만 처리하기 때문에 대각선 이동시 1개만 처리해서 
		// 서로 엇갈리는 경우 발생
	//	switch (player_info.direction)
	//	{
	//	case LEFT:
	//		player_info.direction_rect.SetPos(pos.x - i_size * 2, pos.y);
	//		//item_rect.SetPos(pos.x - i_size, pos.y);
	//		break;
	//	case TOP:
	//		player_info.direction_rect.SetPos(pos.x, pos.y - i_size * 2);
	//		//item_rect.SetPos(pos.x, pos.y - i_size);
	//		break;
	//	case RIGHT:
	//		player_info.direction_rect.SetPos(pos.x + i_size * 2, pos.y);
	//		//item_rect.SetPos(pos.x + i_size, pos.y);
	//		break;
	//	case BOTTOM:
	//		direction_rect.SetPos(pos.x, pos.y + i_size * 2);
	//		//item_rect.SetPos(pos.x, pos.y + i_size);
	//		break;
	//	}

	//	direction_rect.SetRectFromCurrentPos();
	//	item_rect.SetRectFromCurrentPos();
	};
};
