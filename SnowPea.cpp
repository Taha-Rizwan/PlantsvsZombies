#include "SnowPea.h"

SnowPea::SnowPea(int x, int y): Plant(x, y, 100, "./SFML/images/c/snowpea.png", "SnowPea", 71, 71, 10, 50, 8), Shooter(x + 40, y + 5, 3, 5, "./SFML/images/snowBullet.png", 15, 10) {

}
Bullet* SnowPea::shoot() {
	Bullet*	bullet = nullptr;

	if (Shooter::clock.getElapsedTime().asSeconds() >= reloadTime) {
		Shooter::clock.restart();
		bullet = new SnowBullet(Shooter::pos.pos[0], Shooter::pos.pos[1],3);

	}

	return bullet;
}