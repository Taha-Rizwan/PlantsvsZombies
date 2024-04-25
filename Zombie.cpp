#include<iostream>
#include"Zombie.h"
using namespace std;

//Constructor


//returns speed of the zombie
int Zombie::getSpeed()const {
	return speed;
}

int Zombie::getDamage()const {
	return damage;
}

//Makes the zombie move on the board
void Zombie::move(int x, int y) {
	pos.move(x,y);
}
