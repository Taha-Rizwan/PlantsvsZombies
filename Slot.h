#pragma once
#ifndef Position_h
#include "Position.h"
#include<SFML/Graphics.hpp>
class Slot {
public:
	bool filled;
	Position pos;
	sf::RectangleShape rectangle;
	
	
	Slot(int x=0, int y=0);

	void toggleFilled();
	void normalState();
	void draw(sf::RenderWindow& window);
};
#endif