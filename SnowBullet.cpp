#include "SnowBullet.h"

SnowBullet::SnowBullet(int x, int y, int slowTime):Bullet(x,y,5,"./SFML/images/snowBullet.png",20,18.5), slowTime(slowTime) {
	setType("freeze");
}