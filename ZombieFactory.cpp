#include"ZombieFactory.h"
#include <iostream>
//Constructor for ZombieFactory(takes the number of zombies as size)
ZombieFactory::ZombieFactory(int size):size(size),current(0),zombies(new Zombie*[size]),k(0) {
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
void ZombieFactory::drawZombies(sf::RenderWindow& window) {
	for (int i = 0;i < current;i++) {
		zombies[i]->draw(window,zombies[i]->startY);
	}
}

bool ZombieFactory::allDead() {
	int j = 0;
	if (current == size) {
		for (int i = 0; i < current; i++) {
			if (!zombies[i]->getExists())
				j++;
		}
		if (j == current)
			return true;
	}
	return false;
}
bool ZombieFactory::waveDead() {
	int j = 0;
	for (int i = k; i < current; i++) {
		if (!zombies[i]->getExists())
			j++;
	}
	if (j + k == current) {
		k += j;
		return true;
	}
		
	return false;
}

//Moves all the zombies
void ZombieFactory::moveZombies() {
	for (int i = 0;i < current;i++) {
		zombies[i]->move();
		if (zombies[i]->getFreeze()) {
			zombies[i]->checkFrozen();
		}
	}
}

void ZombieFactory::detectExplosion(Position pos, sf::RenderWindow& window, bool* boom) {

	static sf::Clock clock;
	if (!*boom)
		clock.restart();
	if (*boom) {
		sf::Vector2f mid(pos.pos[0] - 80, pos.pos[1] - 100);
		sf::RectangleShape rect;
		rect.setSize(sf::Vector2f(80 * 3, 100 * 3));
		rect.setPosition(mid);

		if (clock.getElapsedTime().asSeconds() >= 2) {
			for (int i = 0; i < current; i++) {
				if (zombies[i]->getSprite()->getGlobalBounds().intersects(rect.getGlobalBounds()) && zombies[i]->getExists()) {
					zombies[i]->toggleExists();
				}
			}
			clock.restart();
			*boom = false;
		}
	}
}

void ZombieFactory::detectCollision(Bullet** bullets, Plant** plants,LawnMower** mowers, int numBullets,int numPlants,int numMowers) {
	
	for (int i = 0; i < current; i++) {
		//Bullet Collision
		for (int j = 0; j < numBullets; j++) {
			if (bullets[j]->getExists() && zombies[i]->getExists()) {
				if (bullets[j]->getSprite()->getGlobalBounds().intersects(zombies[i]->getSprite()->getGlobalBounds())) {
					
					
					if (bullets[j]->getType() != "fume") {
						bullets[j]->toggleExists();
						zombies[i]->hit(5);
					}
					else {
						zombies[i]->hit(0.25);
						
					}
						
					//Snow Bullet
					if (bullets[j]->getType() == "freeze" && !zombies[i]->getFreeze())
					{
						zombies[i]->toggleFreeze();
						std::cout << "Frozen" << std::endl;
					}
				}
			}

		}
		//Plant Collision
		for (int j = 0; j < numPlants; j++) {
			if (plants[j]->getExists()) {
				if (plants[j]->getSprite()->getGlobalBounds().intersects(zombies[i]->getSprite()->getGlobalBounds())){
					if (zombies[i]->getDamage() != 0) {
						zombies[i]->eatPlant(plants[j]);
					}
				}
			}
		}
		//LawnMower Collision
		for (int j = 0;j < numMowers;j++) {
			if (mowers[j]->getExists()){
				if (mowers[j]->getSprite()->getGlobalBounds().intersects(zombies[i]->getSprite()->getGlobalBounds())){
					mowers[j]->setMove();
					zombies[i]->hit(mowers[j]->getDamage());
				}
			}
		}
	}
}


Zombie** ZombieFactory::getZombies() {
	return zombies;
}

int ZombieFactory::getCurrentZombies() {
	return current;
}
bool ZombieFactory::deductLife(){
	for (int i = 0; i < current; i++) {
		if (zombies[i]->getSprite()->getPosition().x <= 207 && zombies[i]->getExists()) {
			zombies[i]->toggleExists();
			return true;
		}
	}
	return false;
}

//Destructor(destroys all of the zombies)
ZombieFactory::~ZombieFactory(){
	for (int i = 0;i < current;i++) {
		delete zombies[i];
	}
	delete[] zombies;
}
