#pragma once
#ifndef Plant.h
#include "Plant.h"
class Wallnut :public Plant {
public:
	Wallnut(int x, int y);
	void roll();
	void draw(RenderWindow& window);
};
#endif