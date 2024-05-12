#pragma once
#include"Zombie.h"
class FootballZombie: public Zombie {
	bool plantAhead;
public:
	FootballZombie(int x, int y,int waitTime);
	void move(bool state);
	void eatPlant(Plant* plant);
	~FootballZombie() {}
};

