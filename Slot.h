#pragma once
#ifndef Position_h
#include "Position.h"
#include<SFML/Graphics.hpp>
#include "Plant.h"
class Slot {
public:
	bool filled;
	Position pos;
	sf::RectangleShape rectangle;
	Plant* plant;
	
	Slot(int x=0, int y=0);
	void checkFilled();
	void toggleFilled();
	void normalState();
	void draw(sf::RenderWindow& window);
};
#endif