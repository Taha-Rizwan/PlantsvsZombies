/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/

#pragma once
#ifndef Bullet_h
#include"Bullet.h"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

class Shooter {
protected:
	Bullet* bullet;
	double reloadTime,bulletSpeed,textureX,textureY;
	std::string bulletSpritePath;
	sf::Clock sClock;
	Position* pos;
	bool canShot;
	sf::SoundBuffer shootSoundBuffer;
	sf::Sound shootSound;
public:
	//Shooter class from which shooting plants inherit from
	Shooter(Position* pos, double reloadTime, int bulletSpeed, std::string bulletSpritePath, double textureX,double textureY);
	//Shoot bullet function for shooters
	virtual Bullet* shoot();

};

#endif