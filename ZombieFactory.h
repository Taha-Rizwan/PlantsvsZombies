#pragma once
#ifndef Zombie_h
#include "Plant.h"
#include"Zombie.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class ZombieFactory {
	Zombie** zombies;
	int size, current;
public:

	//Constructor for ZombieFactory(takes the number of zombies as size)
	ZombieFactory(int size);
	
	//Takes a zombie pointer and stores it in the next available space in zombies pointer array
	void addZombie(Zombie* newZombie);

	//Draws all of the Zombies stored
	void drawZombies(RenderWindow& window);

	//Moves all the zombie
	void moveZombies();

	
	void detectCollision(Bullet** bullets, Plant** plants, int numBullets, int numPlants);

	//Destructor(destroys all of the zombies)
	~ZombieFactory();

};

#endif