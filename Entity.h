/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/
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
	//Entity Class from which All Zombies and Plant inherit from
	Entity(int x, int y, double tolerance, std::string texturePath, std::string name,double textureX,double textureY,int sprites);
	//Draw Function for Entity
	virtual void draw(sf::RenderWindow& window,int y=0);
	//Hit function to consume damage
	virtual bool hit(double damage);
	double getTolerance()const;
	bool getExists()const;
	//Get Name of Entity
	std::string getName()const;
	//Toggle Existence of Entity
	void toggleExists();
	//Function to get sprite for collision
	sf::Sprite* getSprite();
};