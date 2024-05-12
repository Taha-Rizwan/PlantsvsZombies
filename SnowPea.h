/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/

#pragma once
#ifndef Plant_h
#include "Plant.h"
#include "Shooter.h"
#include "SnowBullet.h"

class SnowPea :public Plant, public Shooter {

public:
	//Snow Shooting Plant which shoots snowBullets
	SnowPea(int x, int y);
	Bullet* shoot();


};
#endif