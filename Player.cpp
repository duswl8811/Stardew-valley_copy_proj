#include "stdafx.h"
#include "Player.h"
#include "KeyManager.h"


Player::Player()
{
	player_info.pos.x = PLAYER_WINDOW_POS_X;
	player_info.pos.y = PLAYER_WINDOW_POS_Y;

}

Player::~Player()
{
	Release();
}

bool Player::Initialize()
{
	SetPos(80, 80);

	playerBit = (HBITMAP)LoadImage(NULL, "Stardew_Valley_Player_A.bmp", IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	
	hairBit = (HBITMAP)LoadImage(NULL, "hairstyles.bmp", IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	GetObject(playerBit, sizeof(BITMAP), &playerBmp);
	GetObject(hairBit, sizeof(BITMAP), &hairBmp);

	return true;
}

void Player::Progress()
{
	KeyCheck();

	if (GetState() == 2) {
		//std::cout << GetAniNum() << std::endl;

		SetAniCount((((GetAniCount() + 1) % 4)));
	}

	else
		SetAniNum(0);
}

void Player::Render(HDC _hdc)
{
	// hdc, MemDC 세팅 필요

	// 어떻게 그리지??

	
	memdc = CreateCompatibleDC(_hdc);
	hBit = CreateCompatibleBitmap(_hdc, WINDOW_SIZE_X, WINDOW_SIZE_Y);
	SelectObject(memdc, oldBit);
	oldBit = (HBITMAP)SelectObject(memdc, hBit);
	//PatBlt(memdc, 0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y, WHITENESS);	// 배경 하얗게
																	// FillRect(backMemDC, &rt, (HBRUSH)GetStockObject(WHITE_BRUSH)); //도화지 색 변경
	source_dc = CreateCompatibleDC(memdc);
	edit_dc = CreateCompatibleDC(source_dc);

	// hdc에 붙여넣을 memdc 전체를 bitmap 으로 저장할 것입니다.
	hBit2 = CreateCompatibleBitmap(_hdc, WINDOW_SIZE_X, WINDOW_SIZE_Y);
	StretchBit = CreateCompatibleBitmap(_hdc, size.width, size.height);

	oldBit2 = (HBITMAP)SelectObject(source_dc, hBit2);
	//oldBit2 = (HBITMAP)SelectObject(source_dc, GetStockObject(WHITE_BRUSH));

	BitBlt(memdc, 0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y, source_dc, 0, 0, SRCCOPY);

	oldBit2 = (HBITMAP)SelectObject(source_dc, playerBit); // char_sheet
	oldBit3 = (HBITMAP)SelectObject(edit_dc, StretchBit); // edit_sheet

	// 반대로 그리기
	{
		// 몸체
		TransparentBlt(edit_dc, 0, 0,
			size.width, size.height, 
			//(*map_bmp)[name]->GetMemDC(), 
			source_dc, size.width * player_info.animation_num, size.height * abs(player_info.direction),
			size.width, size.height, RGB(255, 255, 255));

		//std::cout << GetAniNum() << std::endl;
		//std::cout << abs(player_info.direction) << std::endl;


		// 6, 18, 5, 3 등 마법의 숫자 변경 필요
		// 팔
		TransparentBlt(edit_dc, 0, 0,
			size.width, size.height,
			source_dc, 6 * size.width + size.width * player_info.animation_num, size.height * abs(player_info.direction),
			size.width, size.height, RGB(255, 255, 255));

		// 다리
		TransparentBlt(edit_dc, 0, 0,
			size.width, size.height,
			source_dc, 18 * size.width + size.width * player_info.animation_num, size.height * abs(player_info.direction),
			size.width, size.height, RGB(255, 255, 255));

		// hair
		SelectObject(source_dc, oldBit2);
		oldBit2 = (HBITMAP)SelectObject(source_dc, hairBit); // char_sheet

		TransparentBlt(edit_dc, 0, 0,
			size.width, size.height + player_info.animation_num * 5,
			source_dc, size.width * player_info.hair_x, size.height * player_info.hair_y * 3 + size.height * abs(player_info.direction),
			size.width, size.height, RGB(255, 255, 255));


		//// 좌우 뒤집어서 back buffer에 옮기기
		//StretchBlt(memdc, 
		//	player_info.pos.x + size.width / 2 - copysign(size.width / 2, (double)player_info.direction),	// x
		//	player_info.pos.y,																			// y
		//	copysign(size.width, (double)player_info.direction),										// w
		//	size.height,																				// h
		//	edit_dc, 0, 0,																				// hdc, x, y
		//	size.width, size.height, SRCCOPY);															// w, h, option

																										// 좌우 뒤집어서 back buffer에 옮기기
		StretchBlt(memdc,
			0 + size.width / 2 - copysign(size.width / 2, (double)player_info.direction),	// x
			0,																			// y
			copysign(size.width, (double)player_info.direction),										// w
			size.height,																				// h
			edit_dc, 0, 0,																				// hdc, x, y
			size.width, size.height, SRCCOPY);															// w, h, option

	}

	TransparentBlt(_hdc, player_info.pos.x, player_info.pos.y,
		size.width * 2, size.height * 2,
		memdc, 0, 0,
		size.width, size.height, RGB(0, 0, 0));

	//BitBlt(_hdc, 0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y, memdc, 0, 0, SRCCOPY);

	//hbit을 담아 뒀던 것을 다시 oldbit으로 변경해 줍니다.
	SelectObject(edit_dc, oldBit3);
	SelectObject(source_dc, oldBit2);
	SelectObject(memdc, oldBit);
}

void Player::Release() 
{
	// 새로 만들었 던 hbit는 삭제 and memdc를 삭제
	DeleteObject(playerBit);
	DeleteObject(StretchBit);
	DeleteObject(hBit2);
	DeleteObject(hBit2);
	DeleteDC(source_dc);
	DeleteDC(edit_dc);
	DeleteDC(memdc);

	ZeroMemory(&player_info, sizeof(PlayerInfo));
}

void Player::KeyCheck()
{
	DWORD dwKeyState = KeyManager::GetInstance()->GetKeyState();

	if (dwKeyState) {
		if (dwKeyState & KEY_W) {
			
			player_info.pos.y -= player_info.move_speed;
			SetDirection(UP);
		}
		if (dwKeyState & KEY_A) {
			std::cout << player_info.direction << std::endl;
			player_info.pos.x -= player_info.move_speed;
			SetDirection(LEFT);
		}
		if (dwKeyState & KEY_S) {
			player_info.pos.y += player_info.move_speed;
			SetDirection(DOWN);
		}
		if (dwKeyState & KEY_D) {
			player_info.pos.x += player_info.move_speed;
			SetDirection(RIGHT);
		}

		
		SetState(2);
	}

	else
		SetState(0);
		
}