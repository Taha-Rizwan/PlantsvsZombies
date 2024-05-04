#pragma once
#ifndef Plant.h
#include "Plant.h"
class Wallnut :public Plant {
	bool rolling;
public:
	Wallnut(int x, int y);
	void roll();
	void draw(sf::RenderWindow& window, int y = 0);
	bool hit(int damage);
};
#endif