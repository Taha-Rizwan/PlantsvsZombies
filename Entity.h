#pragma once
#include "Position.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include"Position.h"
using namespace sf;
using namespace std;

class Entity {
protected:
	Position pos;
	bool exists;
	int tolerance;
	string name;
	Sprite sprite;
	int sprites;
	Texture texture;
	double textureX;
	double textureY;
	Clock clock;
	int x;
	bool reverse;

public:
	Entity(int x, int y, int tolerance, string texturePath, string name,int textureX,int textureY,int sprites);
	void draw(RenderWindow& window);
	void hit(int damage);
	bool getExists()const;
	void toggleExists();
	
};