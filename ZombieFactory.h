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
	int size, current,k;
	sf::SoundBuffer mowerBuffer,reviveBuffer;
	sf::Sound mowerSound,reviveSound;
	sf::Clock resClock;
	sf::Texture haloTexture;
	sf::Sprite halo;
public:

	//Constructor for ZombieFactory(takes the number of zombies as size)
	ZombieFactory(int size);
	
	//Takes a zombie pointer and stores it in the next available space in zombies pointer array
	void addZombie(Zombie* newZombie);
	void reviveZombie(int x ,int y);
	//Draws all of the Zombies stored
	void drawZombies(sf::RenderWindow& window);

	bool allDead();
	bool waveDead();
	//Moves all the zombie
	void moveZombies(bool state);

	Zombie** getZombies();
	int getCurrentZombies();
	void detectCollision(Bullet** bullets, Plant** plants, LawnMower** mowers, int numBullets, int numPlants, int numMowers,int& score);
	void detectExplosion(Position pos, sf::RenderWindow& window, bool* boom,int& score);
	bool deductLife();
	//Destructor(destroys all of the zombies)
	~ZombieFactory();

};

#endif