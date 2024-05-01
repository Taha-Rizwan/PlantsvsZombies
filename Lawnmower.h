#pragma once
#include"Entity.h"

class LawnMower: public Entity {
	int damage;
	bool move;
public:
	LawnMower(int x, int y);
	void moveMower();
	Sprite* getSprite(){
		return &sprite;
	}
	void setMove();
};