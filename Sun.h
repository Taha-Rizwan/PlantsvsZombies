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
	Sun(int x = 200, int y = -10);
	void draw(sf::RenderWindow& window);
	void move();
	bool collectSun(sf::Event& event,  sf::RenderWindow& window);
	bool isClicked(sf::Vector2f& mousePos);
	void appear();
	bool isCollected()const;
	int getSunProduced()const;
	sf::Sprite getSprite()const;
};


#endif