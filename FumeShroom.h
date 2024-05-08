#pragma once
#ifndef Plant_h
#include "Plant.h"
#include "Shooter.h"
class FumeShroom: public Plant,public Shooter {
public:
	FumeShroom(int x, int y);
	Bullet* shoot();
};

#endif