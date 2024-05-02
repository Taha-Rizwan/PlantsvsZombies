#ifndef GAME_STATE_H
#define GAME_STATE_H

#include"ZombieFactory.h"
#include"Slot.h"
#include"Bullet.h"

class GameState {
	int rows;
	int columns;
	Slot*** grid;
	int score;
	int lives;
	int economy;
	//PlantFactory currentPlants;
	ZombieFactory currentZombies;
	Bullet* currentBullets;
public:
	GameState();
	int getEconomy()const;
	void updateEconomy(int amount);
	~GameState();
};
#endif