#include"Zombie.h"

//Constructor(Members initialized using member initializer list)
Zombie::Zombie(int x, int y, int tolerance, string texturePath, string name, double textureX, double textureY, float speed, int damage, int wait, bool attack, int score, int sprites):Entity(x,y,tolerance,texturePath,name,textureX,textureY, sprites),speed(speed),damage(damage),wait(wait),attack(attack),score(score),startY(0),eat(false) {
	sprite.setScale(2, 2);
}

//returns speed of the zombie
int Zombie::getSpeed()const {
	return speed;
}

int Zombie::getDamage()const {
	return damage;
}

//Makes the zombie move on the board
void Zombie::move() {
	if (!eat) {
		float time;
		time = moveClock.restart().asSeconds();
		pos.set(-speed * time * 2);
	}
}

//Zombie eats plant
void Zombie::eatPlant(Plant* plant) {
	if (exists && plant->getExists()) {
		eat = true;
		startY = 3;
		plant->hit(damage);
		if (!(plant->getExists())) {
			eat = false;
			startY = 0;
		}
	}
}