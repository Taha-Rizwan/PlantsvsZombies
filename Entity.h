#pragma once
#include "Position.h"
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
class Entity {
protected:
	Position pos;
	bool exists;
	int tolerance;
	std::string name;
	sf::Sprite sprite;
	int sprites;
	sf::Texture texture;
	double textureX;
	double textureY;
	sf::Clock clock;
	int x;

public:
	Entity(int x, int y, int tolerance, std::string texturePath, std::string name,double textureX,double textureY,int sprites);
	virtual void draw(sf::RenderWindow& window,int y=0);
	virtual bool hit(int damage);
	bool getExists()const;
	std::string getName()const;
	void toggleExists();
	sf::Sprite* getSprite();
};