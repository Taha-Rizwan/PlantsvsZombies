#pragma once
#ifndef Entity_H
#include"Entity.h"
#include"Plant.h"
#include"Shooter.h"
using namespace std;
class Zombie :public Entity{
protected:
	float speed;
	int damage;
	int wait;
	bool attack;
	bool eat;
	int score;
	//Clock for movement
	Clock moveClock;
public:
	int startY;
	Zombie(int x, int y, int tolerance, string texturePath, string name, double textureX, double textureY, float speed, int damage, int wait, bool attack, int score, int sprites);
	int getSpeed()const;
	int getDamage()const;
	virtual void move();
	void eatPlant(Plant* plant);
	virtual ~Zombie() {}
};
#endif