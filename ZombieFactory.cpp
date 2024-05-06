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
void ZombieFactory::drawZombies(sf::RenderWindow& window) {
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
				if (zombies[i]->getSprite()->getGlobalBounds().intersects(rect.getGlobalBounds())) {
					zombies[i]->hit(250);
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


//Destructor(destroys all of the zombies)
ZombieFactory::~ZombieFactory(){
	for (int i = 0;i < current;i++) {
		delete zombies[i];
	}
	delete[] zombies;
}
