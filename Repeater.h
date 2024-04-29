#pragma once
#ifndef Plant_h
#include "Plant.h"
#include"Shooter.h"

class Repeater : public Plant, public Shooter {
protected:
	bool shot;
	Clock clock;
public:
	Repeater(int x, int y);
	Bullet* shoot();
};

#endif
