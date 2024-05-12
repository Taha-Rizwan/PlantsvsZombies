/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/

#pragma once
#ifndef Position_h
#include "Position.h"
#include<SFML/Graphics.hpp>
#include "Plant.h"
class Slot {
public:

	//Slot class on which plant can be placed. Plant gets placed at midpoint of rectangle
	bool filled;
	Position pos;
	sf::RectangleShape rectangle;
	Plant* plant;
	
	Slot(int x=0, int y=0);
	//Check if its filled
	void checkFilled();
	//toggle filled
	void toggleFilled();
	//Back to normal state
	void normalState();
	void draw(sf::RenderWindow& window);
};
#endif