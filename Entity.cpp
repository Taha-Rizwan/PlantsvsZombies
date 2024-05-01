#include "Entity.h"
//X and Y are Spawn Positions, textureX and textureY are height and width of sprites
Entity::Entity(int x, int y,int tolerance, string texturePath, string name, double textureX,double textureY, int sprites) : pos(x, y), tolerance(tolerance),textureX(textureX),textureY(textureY), name(name),sprites(sprites),x(0) {
		texture.loadFromFile(texturePath);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, textureX, textureY));
		sprite.setScale(2.0,2.0);
		exists = true;
}

//Function for when entity takes damage
void Entity::hit(int damage) {
	tolerance -= damage;
	if (tolerance < 0)
		exists = false;
}
//Draw Function for entity
void Entity::draw(RenderWindow& window){
	if (exists) {
		sprite.setPosition(pos.pos[0], pos.pos[1]);
		//For Sprite Animation
		if (clock.getElapsedTime().asSeconds() > 0.2f) {
			sprite.setTextureRect(IntRect(textureX * x, 0, textureX, textureY));
			if (x >= sprites - 1) {
				x = -1;
			}

				x++;
			clock.restart();
	}

		window.draw(sprite);
	}
}

bool Entity::getExists() const{
	return exists;
}

Sprite* Entity::getSprite() {
	return &sprite;
}

void Entity::toggleExists() {
	exists = !exists;
}