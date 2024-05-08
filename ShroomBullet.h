#pragma once
#ifndef Bullet_h
#include "Bullet.h"

class ShroomBullet : public Bullet {
	int range,x;

public:
	ShroomBullet(int x, int y, int range = 4);
	void move();
	void draw(sf::RenderWindow& window);
};

#endif