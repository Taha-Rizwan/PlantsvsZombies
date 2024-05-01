#include "Wallnut.h"

Wallnut::Wallnut(int x, int y) : Plant(x, y, 49, "./SFML/images/wallnut.png", "Repeater", 27, 31, 10, 50, 5), rolling(true) {}
//Rolling movement
void Wallnut::roll() {
	if(rolling)
	pos.set(5,0);
}

bool Wallnut::hit(int damage) {
	rolling = false;
	return Entity::hit(damage);
}

void Wallnut::draw(RenderWindow& window) {
	if (exists) {
		sprite.setPosition(pos.pos[0], pos.pos[1]);
		//For Sprite Animation
		if (clock.getElapsedTime().asSeconds() > 0.2f) {
			
			if (tolerance > 50) {
				sprite.setTextureRect(IntRect(textureX * x, 0, textureX, textureY));
			}
			else {
				//Rolling has 8 sprites
				if (sprites != 8)
					sprites = 8;
				roll();
				//Some sprites have a different size
				if(x<4)
					sprite.setTextureRect(IntRect((textureX+x-1) * x, textureY * 3, (textureX+x-1), textureY));
				else if(x==4)
					sprite.setTextureRect(IntRect((textureX + x-2) * x, textureY * 3, (textureX + x-4), textureY));
				else
					sprite.setTextureRect(IntRect((textureX+2 ) * x, textureY * 3, (textureX+2  ), textureY));
			}
			if (x >= sprites - 1) {
				x = -1;
			}
				x++;
			clock.restart();
		}

		window.draw(sprite);
	}
	
}