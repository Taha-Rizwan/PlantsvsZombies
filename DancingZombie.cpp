#include"DancingZombie.h"

DancingZombie::DancingZombie(int x, int y, int tolerance, string texturePath, string name, int textureX, int textureY, int speed, int damage, int wait, bool attack, int score, int sprites) : Zombie(x, y, tolerance, texturePath, name, textureX, textureY, speed, damage, wait, attack, score, sprites) {

}

void DancingZombie::move() {
	//Collision Logic/........
	
	
	
	pos.set(-speed,speed);
}