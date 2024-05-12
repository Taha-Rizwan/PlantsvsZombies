/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/

#pragma once
#ifndef Plant_h
#include "Plant.h"
#include"Shooter.h"

class Repeater : public Plant, public Shooter {
protected:
	bool shot;
	sf::Clock clock;
public:
	//Repeater Plant
	Repeater(int x, int y);
	//Shoots twice 
	Bullet* shoot();
};

#endif
