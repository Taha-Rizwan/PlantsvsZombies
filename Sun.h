#pragma once
#ifndef Position_h
#include "Position.h"
#include "SFML/Graphics.hpp"
class Sun {
	Position pos;
	int sunProduced;
	bool collected;
	sf::Texture sunTexture;
	double textureX, textureY;
	sf::Sprite sunSprite;
	int sprites;
	sf::Clock sClock;
public:
	Sun(int x = 200, int y = 0);
	void draw(sf::RenderWindow& window);
	void move();
	void collectSun(sf::Event& event);
	bool isClicked(sf::Vector2f& mousePos);
	sf::Sprite* getSprite(){
		return &sunSprite;
	}
};


#endif