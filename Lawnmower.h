#pragma once
#include"Entity.h"

class LawnMower: public Entity {
	int damage;
	bool move;
public:
	LawnMower(int x, int y);
	void moveMower(bool state);
	void draw(sf::RenderWindow& window);
	sf::Sprite* getSprite(){
		return &sprite;
	}
	int getDamage()const;
	void setMove();
};