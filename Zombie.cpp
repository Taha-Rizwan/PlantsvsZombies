#include"Zombie.h"

//Constructor(Members initialized using member initializer list)
Zombie::Zombie(int x, int y, int tolerance, std::string texturePath, std::string name, double textureX, double textureY, float speed, int damage, int wait, bool attack, int score, int sprites):Entity(x,y,tolerance,texturePath,name,textureX,textureY, sprites),speed(speed),damage(damage),wait(wait),attack(attack),score(score),startY(0),eat(false) {
	sprite.setScale(2, 2);
}

//returns speed of the zombie
int Zombie::getSpeed()const {
	return speed;
}

int Zombie::getDamage()const {
	return damage;
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