#pragma once
#include"Zombie.h"

class FlyingZombie: public Zombie{

public:
<<<<<<< HEAD
	FlyingZombie(int x, int y, int tolerance, string texturePath, string name, int textureX, int textureY, int speed, int damage, int wait, bool attack, int score);
	void move();
=======
	FlyingZombie(int x, int y, int tolerance, string texturePath, string name, int textureX, int textureY, int speed, int damage, int wait, bool attack, int score, int sprites);
	void move(int x,int y);
>>>>>>> b925c800e2d6770e7672dbc309b3a2a6bc2c8264
};
