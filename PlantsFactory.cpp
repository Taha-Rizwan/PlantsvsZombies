#include "PlantFactory.h"
#include<iostream>
PlantFactory::PlantFactory(int * economy,int size):size(45),current(0),currentShooters(0),currentBullets(0),currentSunflowers(0),currentSuns(0), grid(grid), currentOptions(7),explosion(0,0),economy(economy){
	grid = new Slot * *[5];
	for (int i = 0; i < 5; i++) {
		grid[i] = new Slot * [9];
		for (int j = 0; j < 9; j++) {
			grid[i][j] = new Slot((250 + j * 80), (75 + i * 100));
		}
	}
	plants = new Plant * [size];
	shooters = new Shooter * [size];
	bullets = new Bullet * [100];
	sunflowers = new Sunflower * [size];
	suns = new Sun * [size];

	Peashooter* pea = new Peashooter(0, 0);

	Repeater* repeater = new Repeater(0, 0);

	SnowPea* snowPea = new SnowPea(0, 0);

	Wallnut* wallnut = new Wallnut(0, 0);
	
	CherryBomb* cherry = new CherryBomb(0, 0);
	
	Sunflower* sunflower = new Sunflower(0, 0);
	FumeShroom* fume = new FumeShroom(0, 0);
	cherryBomb = cherry;
	options = new Plant * [currentOptions];
	options[0] = pea;
	options[1] = repeater;
	options[2] = snowPea;
	options[3] = wallnut;
	options[4] = cherry;
	options[5] = sunflower;
	options[6] = fume;
	shooterOption = new Shooter * [4];
	shooterOption[0] = pea;
	shooterOption[1] = repeater;
	shooterOption[2] = snowPea;
	shooterOption[3] = fume;
	for (int i = 0; i < currentOptions; i++)
		options[i]->getCardSprite()->setPosition(i * 150, 0);
}


bool PlantFactory::isClicked(sf::RectangleShape& rectangle,sf::Vector2f& mousePos) {
	return rectangle.getGlobalBounds().contains(mousePos);
}
bool PlantFactory::isClicked(sf::Sprite& sprite, sf::Vector2f& mousePos) {
	return sprite.getGlobalBounds().contains(mousePos);
}

void PlantFactory::refreshOptions(int i) {
	
	if (i == 0) {
		Peashooter* pea = new Peashooter(0, 0);
		options[0] = pea;
		shooterOption[0] = pea;
	}
	else if (i == 1) {
		Repeater* repeater = new Repeater(0, 0);
		options[1] = repeater;
		shooterOption[1] = repeater;
	}
	else if (i == 2) {
		SnowPea* snowPea = new SnowPea(0, 0);
		options[2] = snowPea;
		shooterOption[2] = snowPea;
	}
	else if (i == 3) {

		options[3] = new Wallnut(0, 0);
	}
	else if (i == 4) {
		CherryBomb* cherry = new CherryBomb(0, 0);

		options[4] = cherry;
		
				
	}
	else if (i == 5) {
		Sunflower* sunflower = new Sunflower(0, 0);
		options[5] = sunflower;
	}
	else if (i == 6) {
		FumeShroom* fume = new FumeShroom(0, 0);
		options[6] = fume;
		shooterOption[3] = fume;
	}
	for (int i = 0; i < currentOptions; i++)
		options[i]->getCardSprite()->setPosition(i * 150, 0);
}



void PlantFactory::displayOptions(sf::RenderWindow& window, sf::Event& event) {

	static bool found;
	static int row;
	static int col;
	static bool selected = false;
	static int option = 0;
	
	sf::Sprite *card;
	sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	//Drawing each plant card
	for ( int i = 0; i < currentOptions; i++) {
		card = options[i]->getCardSprite();
		window.draw(*card);
		if (!options[i]->getAvailable() || *economy<options[i]->getCost()) {
			card->setColor(sf::Color(255, 255, 255, 128));
		}
		else {
			card->setColor(sf::Color(255, 255, 255, 255));
		}
		if (event.type == sf::Event::MouseButtonPressed && options[i]->getAvailable() && *economy >= options[i]->getCost()) {
			if (isClicked(*card, mouse)) {
				initPos = mouse;
				card->setPosition(mouse);
				card->setColor(sf::Color(255, 255, 255, 128));
				selected = true;
				option = i;
			}
		}
		 

	}		

		//Drag and Drop implementation if a plant card is selected
		if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left) && selected) {
			card = options[option]->getCardSprite();
			if (selected) {
				sf::Vector2f delta = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				card->setPosition(delta);
				card->setScale(0.18, 0.30);
		
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 9; j++) {
						if (grid[i][j]->rectangle.getGlobalBounds().contains(delta) && !grid[i][j]->filled) {
							grid[i][j]->rectangle.setFillColor(sf::Color(0, 255, 0, 128));
							row = i;
							col = j;
							found = true;
							mouse = delta;
						}
						else {
							grid[i][j]->normalState();
						}
						grid[i][j]->draw(window);
						grid[i][j]->checkFilled();
					}
				}

			}
		}
		else if (event.type == sf::Event::MouseButtonReleased) {
			selected = false;
			card = options[option]->getCardSprite();
			card->setScale(0.3, 0.25);
			card->setColor(sf::Color(255, 255, 255, 255));
			card->setPosition(150 * option, 0);
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
				grid[row][col]->plant = options[option];
				plants[current++] = options[option];
				if (option < 3) {
					
				}
				if (option == 6) {
					shooters[currentShooters++] = shooterOption[3];
				}
				else if (option == 5) {
					sunflowers[currentSunflowers++] = (Sunflower *)options[option];
				}
				*economy -= options[option]->getCost();
				options[option]->spawn(grid[row][col]->pos.pos[0], grid[row][col]->pos.pos[1]);
				refreshOptions(option);
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
Position PlantFactory::getExplosion(){
	return explosion;
}
bool PlantFactory::isExplode() {
	if (cherryBomb->getExists()) {
			explosion = cherryBomb->getPos();
			cherryBomb = (CherryBomb*)options[4];
			return true;
	}
	return false;
}

void PlantFactory::displayPlants(sf::RenderWindow& window,sf::Event& event) {

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

	for (int j = 0; j < currentSunflowers; j++) {
		suns[currentSuns] = sunflowers[j]->produce();
		if (suns[currentSuns] != nullptr)
			currentSuns++;
	}

	for (int j = 0; j < currentSuns; j++) {
		suns[j]->draw(window);
		if (suns[j]->collectSun(event, window)) {
			*economy += 50;
		}
	}

}