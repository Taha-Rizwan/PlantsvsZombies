#pragma once
#include"Zombie.h"

class SimpleZombie : public Zombie {
public:
	SimpleZombie(int x, int y,int wait);
	void move(bool state);
	void eatPlant(Plant* plant);
	~SimpleZombie() {}

};
