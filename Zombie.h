#pragma once
#include"Entity.h"
#include"Plant.h"
#include"Shooter.h"
class Zombie :public Entity{
protected:
	float speed;
	int damage;
	int wait;
	bool attack;
	bool eat;
	int score;
	//Clock for movement
	sf::Clock moveClock;
public:
	int startY;
	Zombie(int x, int y, int tolerance, std::string texturePath, std::string name, double textureX, double textureY, float speed, int damage, int wait, bool attack, int score, int sprites);
	int getSpeed()const;
	int getDamage()const;
	virtual void move()=0;
	void eatPlant(Plant* plant);
	virtual ~Zombie() {}
};
