#pragma once
#include"Entity.h"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
using namespace std;
using namespace sf;

class Zombie:public Entity{
protected: 
	int speed;
	int damage;
	int wait;
	bool attack;
	int score;
public:
	Zombie(int x, int y, int tolerance, string texturePath, string name, int textureX, int textureY, int speed, int damage, int wait, bool attack, int score);
	int getSpeed()const;
	int getDamage()const;
	virtual void move(int x, int y);
};
