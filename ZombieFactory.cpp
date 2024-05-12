#include"ZombieFactory.h"
#include <iostream>
//Constructor for ZombieFactory(takes the number of zombies as size)
ZombieFactory::ZombieFactory(int size):size(size),current(0),zombies(new Zombie*[size]),k(0) {
	mowerBuffer.loadFromFile("./SFML/Music/mower.mp3");
	mowerSound.setBuffer(mowerBuffer);
	reviveBuffer.loadFromFile("./SFML/Music/res.mp3");
	reviveSound.setBuffer(reviveBuffer);
	haloTexture.loadFromFile("./SFML/Images/halo.png");
	halo.setTexture(haloTexture);
	halo.setTextureRect(sf::IntRect(0, 0, 2000, 2000));
	halo.setScale(0.05, 0.05);
}

//Takes a zombie pointer and stores it in the next available space in zombies pointer array
void ZombieFactory::addZombie(Zombie* newZombie) {
	if (newZombie != nullptr) {
		if (current < size) {
			zombies[current++] = newZombie;
		} 
		if (newZombie->getName() == "DancingZombie")
			resClock.restart();
	}
}
void ZombieFactory::reviveZombie(int x, int y) {
	bool found = false;
	int k = 0;
	for (int i = 0; i < current; i++) {
		if (!zombies[i]->getExists()) {
			found = true;
			k = i;
			break;
		}
	}

	if (found) {
		reviveSound.play();
		zombies[k]->spawn((x - 100), y,100);
		halo.setPosition((x - 100), (y - 50));
		resClock.restart();
	}

}
//Draws all of the Zombies stored
void ZombieFactory::drawZombies(sf::RenderWindow& window) {
	for (int i = 0;i < current;i++) {
		zombies[i]->draw(window,zombies[i]->startY);
	}
	if (reviveSound.getStatus() == sf::SoundSource::Status::Playing)
		window.draw(halo);
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
void ZombieFactory::moveZombies(bool state) {
		for (int i = 0; i < current; i++) {
			zombies[i]->move(state);
			if (zombies[i]->getFreeze()) {
				zombies[i]->checkFrozen();
			}
			if (zombies[i]->getName() == "DancingZombie" && zombies[i]->getExists()) {
				if (resClock.getElapsedTime().asSeconds() >= 10) {
					reviveZombie(zombies[i]->getPos().pos[0], zombies[i]->getPos().pos[1]);
				}
			}
		}
}

void ZombieFactory::detectExplosion(Position pos, sf::RenderWindow& window, bool* boom,int& score) {

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
					std::cout << "Zombie died\n";
					zombies[i]->toggleExists();
					score +=(zombies[i]->getScore());
				}
			}
			clock.restart();
			*boom = false;
		}
	}
}

void ZombieFactory::detectCollision(Bullet** bullets, Plant** plants,LawnMower** mowers, int numBullets,int numPlants,int numMowers,int& score) {
	
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
					if (zombies[i]->getTolerance() < 0) {
						std::cout << "Zombie died\n";
						score += zombies[i]->getScore();
					}
				}
			}
		}
		//Plant Collision
		for (int j = 0; j < numPlants; j++) {
			if (plants[j]->getExists() && zombies[i]->getExists()) {
				
				if (plants[j]->getSprite()->getGlobalBounds().intersects(zombies[i]->getSprite()->getGlobalBounds())){
					if (plants[j]->getName() == "Wallnut" && plants[j]->getTolarence() < 30) {
						zombies[i]->toggleExists();
						plants[j]->toggleExists();
					}
					else if (zombies[i]->getDamage() != 0 && zombies[i]->getExists()) {
						zombies[i]->eatPlant(plants[j]);
					}
					else if (zombies[i]->getDamage()==0) {
						zombies[i]->setPlantAhead(true);
					}
				}
			}
		}
		//LawnMower Collision
		for (int j = 0;j < numMowers;j++) {
			if (mowers[j]->getExists()){
				if (mowers[j]->getSprite()->getGlobalBounds().intersects(zombies[i]->getSprite()->getGlobalBounds())){
					if (mowerSound.getStatus() != sf::SoundSource::Status::Playing)
						mowerSound.play();
					mowers[j]->setMove();
					zombies[i]->hit(mowers[j]->getDamage());
					score += (zombies[i]->getScore());
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
