#pragma once
#include "Position.h"
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
class Entity {
protected:
	Position pos;
	bool exists;
	double tolerance;
	std::string name;
	sf::Sprite sprite;
	int sprites;
	sf::Texture texture;
	double textureX;
	double textureY;
	sf::Clock clock;
	int x;
	float dt;
public:
	Entity(int x, int y, double tolerance, std::string texturePath, std::string name,double textureX,double textureY,int sprites);
	virtual void draw(sf::RenderWindow& window,int y=0);
	virtual bool hit(double damage);
	double getTolerance()const;
	bool getExists()const;
	std::string getName()const;
	void toggleExists();
	sf::Sprite* getSprite();
};