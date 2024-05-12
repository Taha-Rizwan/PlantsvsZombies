/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/

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
	//Game State function for current state of Level
	GameState(int plantOption, int zombies, bool limited = false);
	//Get current Economy
	int getEconomy()const;
	//Update Current Economy
	void updateEconomy(int amount);
	//Function to Spawn Sun
	void spawnSun();
	//Function to start new wave with number of zombies and options of zombies provided
	void startRound(int* numOfZombies, int zombieOptions);
	//Check if level is over
	bool endLevel();
	//Check if wave / round is over
	bool endRound();
	//Calling all display and gameplay functions
	void gameplay(sf::RenderWindow& window, sf::Event& event,bool state);
	//Display Economy
	void displayEconomy(sf::RenderWindow& window);
	void update(float dt);
	//Fucntion to Display Lives
	void displayLives(sf::RenderWindow& window);
	//Function to getLives
	int getLives();
	~GameState();
};
#endif