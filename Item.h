#pragma once
//#include "Player.h"

// type 1 = È£¹Ì
class Item
{
	/*position pos = { 0,0 };
	int type = 0;
	CRECT collision_rect;*/

public:
	Item();
	~Item();

	/*position GetPos() { return pos; };
	int GetType() { return type; };
	CRECT GetCollideRect() { return collision_rect; };

	void SetPos(position p) { pos = p; 
							collision_rect.SetPos(pos);
							collision_rect.SetRectFromCurrentPos();	};
	void SetPos(int _x, int _y) { pos.x = _x; pos.y = _y; 
								collision_rect.SetPos(pos.x, pos.y); 
								collision_rect.SetRectFromCurrentPos(); };
	void SetType(int t) { type = t; };

	bool CollisionCheck(Player p)
	{
		if (p.GetPos().x - p.GetSize() < collision_rect.r &&
			p.GetPos().y - p.GetSize() < collision_rect.b &&
			p.GetPos().x + p.GetSize() > collision_rect.l &&
			p.GetPos().y + p.GetSize() > collision_rect.t)
			return true;
		return false;
	}*/
};

