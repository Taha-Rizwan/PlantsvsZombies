#include<iostream>
#include"Zombie.h"
using namespace std;

//Constructor(Members initialized using member initializer list)
Zombie::Zombie(int x, int y, int tolerance, string texturePath, string name, int textureX, int textureY, int speed, int damage, int wait, bool attack, int score):Entity(x,y,tolerance,texturePath,name,textureX,textureY),speed(speed),damage(damage),wait(wait),attack(attack),score(score) {
	
}

//returns speed of the zombie
int Zombie::getSpeed()const {
	return speed;
}

int Zombie::getDamage()const {
	return damage;
}

//Makes the zombie move on the board
void Zombie::move(int x, int y) {
	pos.set(x,y);
}
