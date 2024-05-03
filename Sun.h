#pragma once
#ifndef Position_h
#include "Position.h"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
using namespace sf;
class Sun {
	Position pos;
	int sunProduced;
	bool collected;
	Texture sunTexture;
	double textureX, textureY;
	Sprite sunSprite;
	int sprites;
	Clock sClock;
public:
	Sun(int x = 200, int y = 0);
	void draw(RenderWindow& window);
	void move();
	void collectSun(Event& event);
	bool isClicked(Vector2f& mousePos);
	Sprite* getSprite(){
		return &sunSprite;
	}
};


#endif