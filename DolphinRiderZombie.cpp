#include"DolphinRiderZombie.h"

DolphinRiderZombie::DolphinRiderZombie(int x, int y, int tolerance, string texturePath, string name, int textureX, int textureY, int speed, int damage, int wait, bool attack, int score) : Zombie(x, y, tolerance, texturePath, name, textureX, textureY, speed, damage, wait, attack, score) {

}

void DolphinRiderZombie::move() {
	////Collission Logic



	pos.set(-speed);
}