#include"LawnMower.h"

LawnMower::LawnMower(int x,int y):Entity(x,y,1000000,"./SFML/Images/car.png","LawnMower",71,57,2),damage(1000),move(false){
	sprite.setTextureRect(sf::IntRect(0, 0, 71, 57));
	sprite.setScale(0.8, 0.8);
}

void LawnMower::draw(sf::RenderWindow& window) {
	sprite.setPosition(pos.pos[0],pos.pos[1]);
	window.draw(sprite);
}

int LawnMower::getDamage()const{
	return damage;
}
void LawnMower::moveMower(){
	if(move)
	pos.set(20);
}

void LawnMower::setMove() {
	move = true;
}