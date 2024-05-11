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
	int plantOptions;
	PlantFactory plantFactory;
	ZombieFactory zombieFactory;
	Sun sun;
	sf::Sprite ecoBar, *heart;
	sf::Texture ecoBarTexture,heartTexture;
	Bullet* currentBullets;
	LawnMower** mowers;
	sf::Font ecoFont;
	sf::Text ecoText;
public:

	GameState(int plantOption, int zombies, bool limited = false);
	int getEconomy()const;
	void updateEconomy(int amount);
	void spawnSun();
	void startRound(int* numOfZombies, int zombieOptions);
	bool endLevel();
	bool endRound();
	void gameplay(sf::RenderWindow& window, sf::Event& event);
	void displayEconomy(sf::RenderWindow& window);
	void displayLives(sf::RenderWindow& window);
	int getLives();
	~GameState();
};
#endif