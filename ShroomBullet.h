/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/

#pragma once
#ifndef Bullet_h
#include "Bullet.h"

class ShroomBullet : public Bullet {
	int range,x;

public:
	//Bullet of mushroom type for fumeshroom
	ShroomBullet(int x, int y, int range = 4);
	void move(bool state);
	void draw(sf::RenderWindow& window,bool state);
};

#endif