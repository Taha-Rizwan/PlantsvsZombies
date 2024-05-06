#pragma once
#include"Zombie.h"
class FootballZombie: public Zombie {
public:
	FootballZombie(int x, int y);
	void move();
	void eatPlant(Plant* plant);
	~FootballZombie() {}
};

