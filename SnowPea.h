#pragma once
#ifndef Plant_h
#include "Plant.h"
#include "Shooter.h"
#include "SnowBullet.h"

class SnowPea :public Plant, public Shooter {

public:
	SnowPea(int x, int y);
	Bullet* shoot();


};
#endif