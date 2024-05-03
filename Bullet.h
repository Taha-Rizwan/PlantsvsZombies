#pragma once
#ifndef Position_h
#include "Position.h"
#include "SFML/Graphics.hpp"

class Bullet {

	sf::Clock clock;
	sf::Sprite bulletSprite;
	sf::Texture bulletTexture;
	float bulletSpeed;
	bool exists;
	Position pos;
	std::string type;

public:
	Bullet(int x, int y, float bulletSpeed, std::string spritePath, double textureX, double textureY);
	bool getExists();
	void move();
	void draw(sf::RenderWindow& window);
	void toggleExists();
	void setType(std::string t);
	sf::Sprite* getSprite();
};


#endif