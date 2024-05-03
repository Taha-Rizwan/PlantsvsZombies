#pragma once
#ifndef Plant_h
#include "Plant.h"
#include"Shooter.h"

class Repeater : public Plant, public Shooter {
protected:
	bool shot;
	sf::Clock clock;
public:
	Repeater(int x, int y);
	Bullet* shoot();
};

#endif
