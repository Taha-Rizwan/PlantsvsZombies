#include "Entity.h"
//X and Y are Spawn Positions, textureX and textureY are height and width of sprites
Entity::Entity(int x, int y,int tolerance, string texturePath, string name, int textureX, int textureY) : pos(x, y), tolerance(tolerance), name(name) {
		texture.loadFromFile(texturePath);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, textureX, textureY));
		sprite.setScale(1.5,1.5);
	exists = true;
}

//Function for when entity takes damage
void Entity::hit(int damage) {
	tolerance -= damage;
	if (tolerance < 0)
		exists = false;
}
//Draw Function for entity
void Entity::draw(RenderWindow& window, int textureX, int textureY) {
	static int x = 0;

	if (exists) {
		sprite.setPosition(pos.getPos()[0], pos.getPos()[1]);
		//For Sprite Animation
		if (clock.getElapsedTime().asSeconds() > 0.075f) {
			sprite.setTextureRect(IntRect(textureX * x, 0, textureX, textureY));
			if (x == 7)
				x = 0;
			x++;
			clock.restart();
		}
		
		window.draw(sprite);
	}
}

bool Entity::getExists() {
	return exists;
}
void Entity::toggleExists() {
	exists = !exists;
}