#pragma once
#include"Zombie.h"

class DancingZombie : public Zombie {

public:

	DancingZombie(int x, int y, int waitTime);
	void move();
	~DancingZombie() {}
};
