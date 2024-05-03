#ifndef Plant_h
#include "Plant.h"
#include"Shooter.h"

class Peashooter : public Plant, public Shooter {

public:
	Peashooter(int x, int y);
};

#endif
