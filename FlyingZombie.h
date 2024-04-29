#pragma once
#include"Zombie.h"

class FlyingZombie: public Zombie{

public:

	FlyingZombie(int x, int y);
	void move();
	~FlyingZombie() {}
};
