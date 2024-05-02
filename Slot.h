#pragma once
#ifndef Position_h
#include "Position.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
class Slot {
public:
	bool filled;
	Position pos;
	RectangleShape rectangle;
	
	
	Slot(int x=0, int y=0);

	void toggleFilled();

	void draw(RenderWindow& window);
};
#endif