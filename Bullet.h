/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/

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
	//Check Bullet Existence
	bool getExists();
	//For Movement of Bullet, state variable to check pause
	virtual void move(bool state);
	//Draw Fucntion for Bullet
	virtual void draw(sf::RenderWindow& window,bool state);
	//Toggle Existence of bullet
	void toggleExists();
	//Type of Bullet i.e Normal / Frozen / Fume
	void setType(std::string t);
	//Get Function type
	std::string getType();
	//Get BUllet sprite to check sprite collision / intersection
	sf::Sprite* getSprite();
};


#endif