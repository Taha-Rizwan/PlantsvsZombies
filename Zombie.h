/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/

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
	//Parent Zombie class from which every other zombie inherit from
	Zombie(int x, int y, int tolerance, std::string texturePath, std::string name, double textureX, double textureY, float speed, int damage, int wait, bool attack, int score, int sprites);
	int getSpeed()const;
	int getDamage()const;
	std::string getName();
	Position getPos();
	bool getWait();
	//Toggle Freeze
	void toggleFreeze();
	virtual void move(bool state) = 0;
	//Check if frozen, if so, half the speed, and than set it to normal after a certain time
	void checkFrozen();
	bool getFreeze();
	void spawn(int x, int y,int tolarence=0);
	virtual void eatPlant(Plant* plant);
	virtual ~Zombie() {}
};
