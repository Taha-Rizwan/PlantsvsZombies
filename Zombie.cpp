#include"Zombie.h"

//Constructor(Members initialized using member initializer list)
Zombie::Zombie(int x, int y, int tolerance, string texturePath, string name, double textureX, double textureY, float speed, int damage, int wait, bool attack, int score, int sprites):Entity(x,y,tolerance,texturePath,name,textureX,textureY, sprites),speed(speed),damage(damage),wait(wait),attack(attack),score(score) {
	
}

//returns speed of the zombie
int Zombie::getSpeed()const {
	return speed;
}

int Zombie::getDamage()const {
	return damage;
}
Clock bclock;

//Makes the zombie move on the board
void Zombie::move() {

	float time;
	time = bclock.restart().asSeconds();
	Entity::pos.set(-speed * time*1);
}
