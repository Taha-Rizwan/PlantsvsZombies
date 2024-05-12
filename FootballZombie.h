#pragma once
#include"Zombie.h"
class FootballZombie: public Zombie {
	bool plantAhead;
public:
	FootballZombie(int x, int y,int waitTime);
	void move();
	void eatPlant(Plant* plant);
	~FootballZombie() {}
};

