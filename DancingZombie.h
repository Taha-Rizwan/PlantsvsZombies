#pragma once
#include"Zombie.h"

class DancingZombie : public Zombie {

public:

	DancingZombie(int x, int y);
	void move();
	~DancingZombie() {}
};
