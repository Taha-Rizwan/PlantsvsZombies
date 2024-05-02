#pragma once
#include"Zombie.h"

class SimpleZombie : public Zombie {
public:
	SimpleZombie(int x, int y);
	void move();
	~SimpleZombie() {}

};
