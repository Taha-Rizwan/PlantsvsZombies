#include"Zombie.h"
#include <iostream>
//Constructor(Members initialized using member initializer list)
Zombie::Zombie(int x, int y, int tolerance, std::string texturePath, std::string name, double textureX, double textureY, float speed, int damage, int wait, bool attack, int score, int sprites):Entity(x,y,tolerance,texturePath,name,textureX,textureY, sprites),speed(speed),damage(damage),wait(wait),attack(attack),score(score),startY(0),eat(false),freeze(false) {
	sprite.setScale(2, 2);
}

//returns speed of the zombie
int Zombie::getSpeed()const {
	return speed;
}

int Zombie::getDamage()const {
	return damage;
}

void Zombie::spawn(int x, int y,int tolerance) {
	pos.pos[0] = x;
	pos.pos[1] = y;
	Entity::clock.restart();
	if (tolerance != 0)
		tolerance = tolerance;
	toggleExists();
}
void Zombie::toggleFreeze() {
	freeze = !freeze;
	if (freeze) {
		speed /= 2;
		freezeClock.restart();
		}
}
void Zombie::checkFrozen() {
	if (freeze && freezeClock.getElapsedTime().asSeconds() >= 2) {
		std::cout << "Unfrozen" << std::endl;
		toggleFreeze();
		speed *= 2;
	}
		
}

bool Zombie::getWait() {
	if (waitClock.getElapsedTime().asSeconds() >= wait)
		return false;
	moveClock.restart();
	return true;
}

std::string Zombie::getName() {
	return name;
}

bool Zombie::getFreeze() {
	return freeze;
}
Position Zombie::getPos() {
	return pos;
}

//Zombie eats plant
void Zombie::eatPlant(Plant* plant) {
	if (exists && plant->getExists()){
		eat = true;
		//startY = 3;
		plant->hit(damage);
		if (!(plant->getExists())) {
			eat = false;
			startY = 0;
		}
	}
}