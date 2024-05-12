/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/
#pragma once
#include"Zombie.h"

class FlyingZombie: public Zombie{

public:
	//Flying Zombie
	FlyingZombie(int x, int y,int waitTime);
	//Movement Function for Flying Zombie
	void move(bool state);
	~FlyingZombie() {}
};
