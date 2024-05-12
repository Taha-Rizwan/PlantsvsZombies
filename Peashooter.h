/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/

#pragma once
#ifndef Plant_h
#include "Plant.h"
#include"Shooter.h"

class Peashooter : public Plant, public Shooter {

public:
	//PeaShooter
	Peashooter(int x, int y);
	//Shoot function for peashooter which only shoots when it exists
	Bullet* shoot();
};

#endif
