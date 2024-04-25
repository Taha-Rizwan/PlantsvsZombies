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

	int getSpeed()const;
	int getDamage()const;
	void move(int x, int y);
};