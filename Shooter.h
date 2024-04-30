#pragma once
#ifndef Bullet_h
#include"Bullet.h"
#include "SFML/System.hpp"
using namespace sf;
using namespace std;

class Shooter {
protected:
	Bullet* bullet;
	float reloadTime,bulletSpeed,textureX,textureY;
	string bulletSpritePath;
	Clock clock;
	Position pos;

public:
	Shooter(int x,int y, float reloadTime, int bulletSpeed, string bulletSpritePath, double textureX,double textureY);

	Bullet* shoot();

};

#endif