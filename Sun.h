/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/

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
	//Sun Class
	Sun(int x = 200, int y = -10);
	//Draw Sun
	void draw(sf::RenderWindow& window);
	//Movement of Sun
	void move();
	//check if SUn is collected
	bool collectSun(sf::Event& event,  sf::RenderWindow& window);
	//check if sun is clicked
	bool isClicked(sf::Vector2f& mousePos);
	void appear();

	bool isCollected()const;
	int getSunProduced()const;
	sf::Sprite getSprite()const;
};


#endif