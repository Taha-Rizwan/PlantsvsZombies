#pragma once
#ifndef Bullet_h
#include"Bullet.h"
#include "SFML/System.hpp"


class Shooter {
protected:
	Bullet* bullet;
	double reloadTime,bulletSpeed,textureX,textureY;
	std::string bulletSpritePath;
	sf::Clock sClock;
	Position* pos;
	bool canShot;
public:
	Shooter(Position* pos, double reloadTime, int bulletSpeed, std::string bulletSpritePath, double textureX,double textureY);

	virtual Bullet* shoot();

};

#endif