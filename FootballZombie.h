/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/
#pragma once
#include"Zombie.h"
class FootballZombie: public Zombie {
public:
	FootballZombie(int x, int y,int waitTime);
	//Movement FUnction for FOotball Zombie
	void move(bool state);
	~FootballZombie() {}
};

