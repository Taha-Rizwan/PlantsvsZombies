/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/
#pragma once
#include"Zombie.h"

class DancingZombie : public Zombie {
public:
	//Dancing Zombie
	DancingZombie(int x, int y, int waitTime);
	//Movement of Dancing Zombie
	void move(bool state);
	~DancingZombie() {}
};
