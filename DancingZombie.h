#pragma once
#pragma once
#include"Zombie.h"

class DancingZombie : public Zombie {

public:
	DancingZombie(int x, int y, int tolerance, string texturePath, string name, int textureX, int textureY, int speed, int damage, int wait, bool attack, int score, int sprites);
	void move(int x,int y);
};
