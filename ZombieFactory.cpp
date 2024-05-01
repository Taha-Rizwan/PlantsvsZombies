#include"ZombieFactory.h"

//Constructor for ZombieFactory(takes the number of zombies as size)
ZombieFactory::ZombieFactory(int size):size(size),current(0),zombies(new Zombie*[size]) {
}

//Takes a zombie pointer and stores it in the next available space in zombies pointer array
void ZombieFactory::addZombie(Zombie* newZombie) {
	if (newZombie != nullptr) {
		if (current < size) {
			zombies[current++] = newZombie;
		}
	}
}

//Draws all of the Zombies stored
void ZombieFactory::drawZombies(RenderWindow& window) {
	for (int i = 0;i < current;i++) {
		zombies[i]->draw(window,zombies[i]->startY);
	}
}

//Moves all the zombies
void ZombieFactory::moveZombies() {
	for (int i = 0;i < current;i++) {
		zombies[i]->move();
	}
}

void ZombieFactory::detectCollision(Bullet** bullets, Plant** plants, int numBullets,int numPlants) {
	
	for (int i = 0; i < current; i++) {
		//Bullet Collision
		for (int j = 0; j < numBullets; j++) {
			if (bullets[j]->getExists()) {
				if (bullets[j]->getSprite()->getGlobalBounds().intersects(zombies[i]->getSprite()->getGlobalBounds())) {
					zombies[i]->hit(5);
					bullets[j]->toggleExists();
				}
			}
		}
		//Plant Collision
		for (int j = 0; j < numPlants; j++) {
			if (plants[j]->getExists()) {
				if (plants[j]->getSprite()->getGlobalBounds().intersects(zombies[i]->getSprite()->getGlobalBounds())) {
					zombies[i]->eatPlant(plants[j]);
				}
			}
		}
	}
}


//Destructor(destroys all of the zombies)
ZombieFactory::~ZombieFactory(){
	for (int i = 0;i < current;i++) {
		delete zombies[i];
	}
	delete[] zombies;
}
