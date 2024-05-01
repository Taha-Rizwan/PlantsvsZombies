#include"LawnMower.h"

LawnMower::LawnMower(int x,int y):Entity(x,y,1000000,"./SFML/Images/lawnMower.png","LawnMower",70,57,2),damage(60){

}

void LawnMower::moveMower(){
	pos.set(30);
}