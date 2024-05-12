#pragma once
#include"Zombie.h"

class DancingZombie : public Zombie {
	bool plantAhead;
public:
	DancingZombie(int x, int y, int waitTime);
	void move(bool state);
	~DancingZombie() {}
};
