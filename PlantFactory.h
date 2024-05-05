#pragma once
#ifndef Slot_h
#include "Slot.h"
#include "SnowPea.h"
#include"Peashooter.h"
#include"Repeater.h"
#include"Wallnut.h"
class PlantFactory {
protected:
	int size, current, currentShooters,currentBullets, currentOptions;
	Plant** plants;
	Shooter** shooters;
	Slot*** grid;
	Bullet** bullets;
	sf::Vector2f initPos;
	Plant** options;
	Shooter** shooterOption;
public:
	PlantFactory(Slot***grid,int size=45);
	bool isClicked(sf::RectangleShape& rectangle, sf::Vector2f& mousePos);
	bool isClicked(sf::Sprite& sprite, sf::Vector2f& mousePos);
	void buyPlant(int& economy);
	Bullet** getBullets();
	Plant** getPlants();
	int getCurrentPlants()const;
	int getCurrentBullets()const;
	void displayOptions(sf::RenderWindow& window,sf::Event& event);
	void displayPlants(sf::RenderWindow& window);
	void refreshOptions(int i);
};

#endif