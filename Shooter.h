#pragma once
#ifndef Bullet_h
#include"Bullet.h"
#include "SFML/System.hpp"
using namespace sf;
using namespace std;

class Shooter {
protected:
	Bullet* bullet;
	int reloadTime,  bulletSpeed,textureX,textureY;
	string bulletSpritePath;
	Clock clock;
	Position pos;

public:
	Shooter(int x,int y, int reloadTime, int bulletSpeed, string bulletSpritePath, int textureX, int textureY);

	Bullet* shoot();

};

#endif