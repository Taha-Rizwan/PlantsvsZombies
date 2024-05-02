#pragma once
#ifndef Slot_h
#include "Slot.h"
#include "SnowPea.h"
#include"Peashooter.h"
#include"Repeater.h"
#include"Wallnut.h"
class PlantFactory {
protected:
	int size, current, currentShooters,currentBullets;
	Plant** plants;
	Shooter** shooters;
	Slot*** grid;
	Bullet** bullets;
	Sprite card;
	Texture cardTexture;
	Vector2f initPos;
public:
	PlantFactory(Slot***grid,int size=45);
	bool isClicked(RectangleShape& rectangle, Vector2f& mousePos);
	bool isClicked(Sprite& sprite, Vector2f& mousePos);
	void buyPlant(int& economy);
	Bullet** getBullets();
	Plant** getPlants();
	int getCurrentPlants()const;
	int getCurrentBullets()const;
	void displayOptions(RenderWindow& window,Event& event);
	void displayPlants(RenderWindow& window);
};

#endif