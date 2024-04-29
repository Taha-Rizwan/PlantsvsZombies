#pragma once
#include"Zombie.h"

class FlyingZombie: public Zombie{

public:
	FlyingZombie(int x, int y, int tolerance, string texturePath, string name, int textureX, int textureY, int speed, int damage, int wait, bool attack, int score);
	void move();
};
