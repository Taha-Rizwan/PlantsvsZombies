#pragma once
#ifndef Position_h
#include "Position.h"
#include "SFML/Graphics.hpp"

class Bullet {
protected:
	sf::Clock clock;
	sf::Sprite bulletSprite;
	sf::Texture bulletTexture;
	float bulletSpeed;
	bool exists;
	Position pos;
	std::string type;
	double textureX, textureY;

public:
	Bullet(int x, int y, float bulletSpeed, std::string spritePath, double textureX, double textureY);
	bool getExists();
	virtual void move();
	virtual void draw(sf::RenderWindow& window);
	void toggleExists();
	void setType(std::string t);
	std::string getType();
	sf::Sprite* getSprite();
};


#endif