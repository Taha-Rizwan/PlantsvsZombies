#pragma once
#ifndef Position_h
#include "Position.h"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
using namespace std;
using namespace sf;
class Bullet {

	Clock clock;
	Sprite bulletSprite;
	Texture bulletTexture;
	float bulletSpeed;
	bool exists;
	Position pos;
	string type;

public:
	Bullet(int x, int y, float bulletSpeed, string spritePath, double textureX, double textureY);
	bool getExists();
	void move();
	void draw(RenderWindow& window);
	void toggleExists();
	void setType(string t);
	Sprite* getSprite();
};


#endif