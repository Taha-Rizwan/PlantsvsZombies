/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/
#pragma once
#ifndef Plant.h
#include "Plant.h"
class Wallnut :public Plant {
	bool rolling;
public:
	//Wallnut Class
	Wallnut(int x, int y);
	//Wallnut starts to roll if tolerance gets lower than a certain limit
	void roll();
	void draw(sf::RenderWindow& window, int y = 0);
	
	bool hit(int damage);
};
#endif