#include "SnowPea.h"

SnowPea::SnowPea(int x, int y): Plant(x, y, 100, "./SFML/images/c/snowpea.png", "SnowPea", 71, 71, 10, 175, 8,"./SFML/images/snowpeaCard.png"), Shooter(&(Plant::pos),3, 20, "./SFML/images/snowBullet.png", 15, 10) {

}
Bullet* SnowPea::shoot() {
	Bullet*	bullet = nullptr;

	if (Shooter::sClock.getElapsedTime().asSeconds() >= reloadTime && exists) {
		Shooter::sClock.restart();
		bullet = new SnowBullet(Shooter::pos->pos[0], Shooter::pos->pos[1],3);

	}

	return bullet;
}