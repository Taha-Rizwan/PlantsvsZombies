#include "PlantFactory.h"
#include<iostream>
using namespace std;
PlantFactory::PlantFactory(Slot***grid,int size):size(45),current(0),currentShooters(0),currentBullets(0), grid(grid) {
	plants = new Plant * [size];
	shooters = new Shooter * [size];
	bullets = new Bullet * [100];
	cardTexture.loadFromFile("./SFML/images/peashooterCard.png");
	card.setTexture(cardTexture);
	card.setTextureRect(IntRect(0, 0, 530, 340));
	card.setScale(0.3, 0.25);
	card.setPosition(20, 20);
}


bool PlantFactory::isClicked(RectangleShape& rectangle, Vector2f& mousePos) {
	return rectangle.getGlobalBounds().contains(mousePos);
}
bool PlantFactory::isClicked(Sprite& sprite, Vector2f& mousePos) {
	return sprite.getGlobalBounds().contains(mousePos);
}


void PlantFactory::displayOptions(RenderWindow& window, Event& event) {

	static bool found;
	static int row;
	static int col;
	static bool selected = false;
	window.draw(card);
	Vector2f mouse(event.mouseButton.x, event.mouseButton.y);
	if (event.type == Event::MouseButtonPressed) {
		if (isClicked(card, mouse)) {
			initPos = mouse;
			card.setPosition(mouse);
			card.setColor(Color(255, 255, 255, 128));
			selected = true;
		}




	}
	else if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		
		if (selected) {
			Vector2f delta(event.mouseMove.x * 1.2, event.mouseMove.y);
			card.setPosition(delta - initPos);
			card.setScale(0.18, 0.30);

			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 9; j++) {
					if (grid[i][j]->rectangle.getGlobalBounds().contains(delta) && !grid[i][j]->filled) {
						grid[i][j]->rectangle.setFillColor(Color(0, 255, 0, 128));
						row = i;
						col = j;
						found = true;
						mouse = delta;
					}
					else {
						grid[i][j]->normalState();
					}
					grid[i][j]->draw(window);
				}
			}

		}
	}
	else if (event.type == Event::MouseButtonReleased) {
		selected = false;
		card.setPosition(20, 20);
		card.setScale(0.3, 0.2);
		card.setColor(Color(255, 255, 255, 255));
		bool wasOn = false;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				if (isClicked(grid[i][j]->rectangle, mouse)) {
					wasOn = true;
					break;
				}
			}
		}
		if (found && wasOn) {
			grid[row][col]->toggleFilled();
			Peashooter* pea = new Peashooter(grid[row][col]->pos.pos[0], grid[row][col]->pos.pos[1]);
			plants[current++] = pea;
			shooters[currentShooters++] = pea;
			found = false;
		}
	}

}


Bullet** PlantFactory::getBullets() {
	return bullets;
}

Plant** PlantFactory::getPlants() {
	return plants;
}
int PlantFactory::getCurrentBullets()const{
	return currentBullets;
}
int PlantFactory::getCurrentPlants()const{
	return current;
}
void PlantFactory::displayPlants(RenderWindow& window) {

	for (int i = 0; i < current; i++) {
		
		plants[i]->draw(window);
	}
	for (int j = 0; j < currentShooters; j++) {
		bullets[currentBullets] = shooters[j]->shoot();
		if (bullets[currentBullets] != nullptr) {
			currentBullets++;
		}
	}

	for (int j = 0; j < currentBullets; j++) {
		if (bullets[j]->getExists())
			bullets[j]->draw(window);
	}
}