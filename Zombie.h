#pragma once
#ifndef Entity_H
#include"Entity.h"
using namespace std;


class Zombie:public Entity{
protected: 
	int speed;
	int damage;
	int wait;
	bool attack;
	int score;
public:
	Zombie(int x, int y, int tolerance, string texturePath, string name, int textureX, int textureY, int speed, int damage, int wait, bool attack, int score, int sprites);
	int getSpeed()const;
	int getDamage()const;
	virtual void move();
};
#endif