#pragma once
#ifndef Plant_h
#include "Plant.h"

class CherryBomb : public Plant {
	int explodeTime;
public:
	CherryBomb(int x, int y);
	void draw(sf::RenderWindow& window, int y = 0);
	Position getPos();
};

#endif