#pragma once
#ifndef Bullet_h
#include "Bullet.h"

class SnowBullet : public Bullet {
protected:
	int slowTime;

public:
	SnowBullet(int x, int y, int slowTime);
};


#endif