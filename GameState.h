#ifndef GAME_STATE_H
#define GAME_STATE_H
#include"ZombieFactory.h"
#include"PlantFactory.h"
#include"Lawnmower.h"
#include"Slot.h"
#include"Bullet.h"
#include "Sun.h"

class GameState {
	int rows;
	int columns;
	int score;
	int lives;
	int economy;
	PlantFactory plantFactory;
	ZombieFactory zombieFactory;
	Sun suns;
	sf::Sprite ecoBar;
	sf::Texture ecoBarTexture;
	Bullet* currentBullets;
	LawnMower** mowers;
	sf::Font ecoFont;
	sf::Text ecoText;
public:

	GameState();
	int getEconomy()const;
	void updateEconomy(int amount);
	void spawnSun();
	void startRound();
	void gameplay(sf::RenderWindow& window, sf::Event& event);
	void displayEconomy(sf::RenderWindow& window);
	~GameState();
};
#endif