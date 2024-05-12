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
	PlantFactory(int* economy,int size=45, bool limited=false);
	bool isClicked(sf::RectangleShape& rectangle, sf::Vector2f& mousePos);
	bool isClicked(sf::Sprite& sprite, sf::Vector2f& mousePos);
	Bullet** getBullets();
	bool isExplode();
	Plant** getPlants();
	int getCurrentPlants()const;
	int getCurrentBullets();
	void displayOptions(sf::RenderWindow& window,sf::Event& event, int plantOptions);
	void displayPlants(sf::RenderWindow& window,sf::Event& event,bool state);
	void refreshOptions(int i);
	void produceSun();
	void displayShovel(sf::RenderWindow& window);
	Position getExplosion();
	void update(float dt);
	~PlantFactory();
};

#endif