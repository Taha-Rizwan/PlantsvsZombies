#pragma once
#ifndef Zombie_h
#include "Plant.h"1
#include"LawnMower.h"
#include"Zombie.h"
#include "SimpleZombie.h"
#include"FootballZombie.h"
#include"DancingZombie.h"
#include"FlyingZombie.h"
#include <SFML/Graphics.hpp>

class ZombieFactory {
	Zombie** zombies;
	int size, current;
public:

	//Constructor for ZombieFactory(takes the number of zombies as size)
	ZombieFactory(int size);
	
	//Takes a zombie pointer and stores it in the next available space in zombies pointer array
	void addZombie(Zombie* newZombie);

	//Draws all of the Zombies stored
	void drawZombies(sf::RenderWindow& window);

	bool allDead();

	//Moves all the zombie
	void moveZombies();

	Zombie** getZombies();
	int getCurrentZombies();
	void detectCollision(Bullet** bullets, Plant** plants, LawnMower** mowers, int numBullets, int numPlants, int numMowers);
	void detectExplosion(Position pos, sf::RenderWindow& window, bool* boom);
	bool deductLife();
	//Destructor(destroys all of the zombies)
	~ZombieFactory();

};

#endif