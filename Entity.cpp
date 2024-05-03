#include "Entity.h"
//X and Y are Spawn Positions, textureX and textureY are height and width of sprites
Entity::Entity(int x, int y,int tolerance, std::string texturePath, std::string name, double textureX,double textureY, int sprites) : pos(x, y), tolerance(tolerance),textureX(textureX),textureY(textureY), name(name),sprites(sprites),x(0) {
		texture.loadFromFile(texturePath);
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0, 0, textureX, textureY));
		//sprite.setScale(2.0,2.0);
		exists = true;
}

//Function for when entity takes damage
bool Entity::hit(int damage) {

	tolerance -= damage;
	if (tolerance < 0)
		exists = false;

	return exists;
}

//Function for getting the name of entity
std::string Entity::getName() const{
	return name;
}

//Draw Function for entity
void Entity::draw(sf::RenderWindow& window,int y){
	if (exists) {
		sprite.setPosition(pos.pos[0], pos.pos[1]);
		//For Sprite Animation
		if (clock.getElapsedTime().asSeconds() > 0.2f) {
			sprite.setTextureRect(sf::IntRect(textureX * x, y*textureY, textureX, textureY));
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

sf::Sprite* Entity::getSprite() {
	return &sprite;
}

void Entity::toggleExists() {
	exists = !exists;
}