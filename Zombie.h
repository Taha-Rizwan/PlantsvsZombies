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
	sf::Clock freezeClock;
	sf::Clock waitClock;
	bool freeze;
public:
	int startY;
	Zombie(int x, int y, int tolerance, std::string texturePath, std::string name, double textureX, double textureY, float speed, int damage, int wait, bool attack, int score, int sprites);
	int getSpeed()const;
	int getDamage()const;
	bool getWait();
	void toggleFreeze();
	virtual void move()=0;
	void checkFrozen();
	bool getFreeze();
	void spawn(int x, int y);
	virtual void eatPlant(Plant* plant);
	virtual ~Zombie() {}
};
