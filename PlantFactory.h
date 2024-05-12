/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/
#pragma once
#ifndef Slot_h
#include "Slot.h"
#include "SnowPea.h"
#include"Peashooter.h"
#include"Repeater.h"
#include"Wallnut.h"
#include "CherryBomb.h"
#include"Sunflower.h"
#include "FumeShroom.h"
#include"Vector.h"
class PlantFactory {
protected:
	int size, current, currentShooters, currentBullets, currentSunflowers, currentSuns, currentOptions;
	Plant** plants;
	Shooter** shooters;
	Slot*** grid;
	Vector<Bullet>bullets;
	sf::Vector2f initPos;
	Plant** options;
	Shooter** shooterOption;
	CherryBomb* cherryBomb;
	Sunflower** sunflowers;
	Sun** suns;
	Position explosion;
	int* economy;
	bool limited;
	sf::Texture shovelTexture;
	sf::Sprite shovelSprite;
	bool shovelSelected;
	sf::SoundBuffer plantBuffer,shovelBuffer;
	sf::Sound plantSound,shovelSound;
public:
	//Plant Factory Class that manages all plants and also has shop functionality
	PlantFactory(int* economy,int size=45, bool limited=false);
	//Checks if rectangle is clicked
	bool isClicked(sf::RectangleShape& rectangle, sf::Vector2f& mousePos);
	//Checks is sprite is clicked
	bool isClicked(sf::Sprite& sprite, sf::Vector2f& mousePos);
	//Gets current Bullets
	Bullet** getBullets();
	//Check for cherrybomb explosion
	bool isExplode();
	//Gets all the current plants
	Plant** getPlants();
	//Gets current number of plants
	int getCurrentPlants()const;
	//Gets current number of bullets
	int getCurrentBullets();
	//Displays the shop with current plant options + drag and drop implementation + Shovel Implementation
	void displayOptions(sf::RenderWindow& window,sf::Event& event, int plantOptions);
	//Display all current alive plants on the grid
	void displayPlants(sf::RenderWindow& window,sf::Event& event,bool state);
	//Refresh plant options after plant is purchased
	void refreshOptions(int i);
	//Drop sun
	void produceSun();
	//Display the shovel
	void displayShovel(sf::RenderWindow& window);
	//Get position of explosion
	Position getExplosion();
	void update(float dt);
	~PlantFactory();
};

#endif