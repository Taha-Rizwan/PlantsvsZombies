#pragma once
#pragma once
#include"Zombie.h"

class DolphinRiderZombie : public Zombie {

public:
	DolphinRiderZombie(int x, int y);
	void move();
	~DolphinRiderZombie() {}
};
