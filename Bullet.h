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

public:
	Bullet(int x, int y, float bulletSpeed, string spritePath, int textureX, int textureY);
	bool getExists();
	void move();
	void draw(RenderWindow& window);
	void toggleExists();
};


#endif