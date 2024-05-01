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

public:
	Entity(int x, int y, int tolerance, string texturePath, string name,double textureX,double textureY,int sprites);
	virtual void draw(RenderWindow& window,int y=0);
	virtual bool hit(int damage);
	bool getExists()const;
	string getName()const;
	void toggleExists();
	Sprite* getSprite();
};