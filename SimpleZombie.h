/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/

#pragma once
#include"Zombie.h"

class SimpleZombie : public Zombie {
public:
	//Simple Zombie
	SimpleZombie(int x, int y,int wait);
	//Movement of Simple Zombie
	void move(bool state);
	//Eating Plant if colliding with plant
	void eatPlant(Plant* plant);
	~SimpleZombie() {}

};
