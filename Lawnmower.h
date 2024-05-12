/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/
#pragma once
#include"Entity.h"

class LawnMower: public Entity {
	int damage;
	bool move;
public:
	//Mower which mows down the entire row on collision with a zombie
	LawnMower(int x, int y);
	//Movement of mower
	void moveMower(bool state);
	//Draw Mower
	void draw(sf::RenderWindow& window);
	sf::Sprite* getSprite(){
		return &sprite;
	}
	//Get Mower Damage
	int getDamage()const;

	void setMove();
};