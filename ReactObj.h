#pragma once
//#include "Player.h"

// type 1 = ¶¥
// state 0 = idel, state 1 = react;
class ReactObj
{
	/*position pos = { 0,0 };
	int type = 0;
	int state = 0;
	CRECT collision_rect;*/

public:
	ReactObj();
	~ReactObj();

	/*position GetPos() { return pos; };
	int GetType() { return type; };
	int GetState() { return state; }
	CRECT GetCollideRect() { return collision_rect; };

	void SetPos(position p) {
		pos = p;
		collision_rect.SetPos(pos);
		collision_rect.SetRectFromCurrentPos();
	};
	void SetPos(int _x, int _y) {
		pos.x = _x; pos.y = _y;
		collision_rect.SetPos(pos.x, pos.y);
		collision_rect.SetRectFromCurrentPos();
	};
	void SetType(int t) { type = t; };
	void SetState(int s) { state = s; };

	bool CollisionCheck(Player p)
	{
		if (p.GetDirectionRect().l < collision_rect.r &&
			p.GetDirectionRect().t < collision_rect.b &&
			p.GetDirectionRect().r > collision_rect.l &&
			p.GetDirectionRect().b > collision_rect.t)
			return true;
		return false;
	}*/
};

