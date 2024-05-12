/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/
#pragma once
#ifndef Plant_h
#include "Plant.h"
#include "Shooter.h"
class FumeShroom: public Plant,public Shooter {
public:
	//FumeShroom
	FumeShroom(int x, int y);
	//Shoot Function which shoots bullet of Fume Type
	Bullet* shoot();
};

#endif