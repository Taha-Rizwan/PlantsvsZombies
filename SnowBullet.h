/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/

#pragma once
#ifndef Bullet_h
#include "Bullet.h"

class SnowBullet : public Bullet {
protected:
	int slowTime;

public:
	//Bullet of type freeze which freezes enemies
	SnowBullet(int x, int y, int slowTime);
};


#endif