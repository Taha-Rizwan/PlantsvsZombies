#include"LawnMower.h"

LawnMower::LawnMower(int x,int y):Entity(x,y,1000000,"./SFML/Images/lawnMower.png","LawnMower",70,57,2),damage(60),move(false){
	sprite.setScale(2, 2);
}

void LawnMower::moveMower(){
	if(move)
	pos.set(20);
}

void LawnMower::setMove() {
	move = true;
}