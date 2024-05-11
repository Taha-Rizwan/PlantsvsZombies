#include "Level2.h"
#include "iostream"
Level2::Level2() : Level(2, 20, 4, 4, "Zombie Outskirts","Cherry Bomb Unlocked","Faster Zombie Waves","Limited Resources") {

}

void Level2::createBack(sf::RenderWindow& window) {
	//Drawing the background
	sf::Image map_image;
	map_image.loadFromFile("./SFML/Images/dayFast.png");
	sf::Texture map;
	map.loadFromImage(map_image);
	sf::Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	if (!roundStart || (roundStart && gameState.endRound()))
		s_map.setColor(sf::Color(255, 255, 255, 128));
	else
		s_map.setColor(sf::Color(255, 255, 255, 255));
	window.draw(s_map);
}

void Level2::displayChallenges(sf::RenderWindow& window, sf::Event event) {

	for (int i = 0; i < 2; i++) {
		window.draw(challengesText[i]);
	}
	window.draw(button);
	window.draw(nameText);
	if (event.type == sf::Event::MouseButtonPressed) {
		sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		if (button.getGlobalBounds().contains(mouse)) {
			roundStart = true;
			int* numZombies = new int[numOfZombies];
			numZombies[0] = 10;
			numZombies[1] = 5;
			numZombies[2] = 3;
			numZombies[3] = 2;

			gameState.startRound(numZombies, numOfZombies);
		}
	}

}
void Level2::displayLevel(sf::RenderWindow& window, sf::Event event) {
	createBack(window);
	if (!roundStart)
		displayChallenges(window, event);
	if (roundStart && !gameState.endRound()) {
		gameState.gameplay(window, event);

	}
	else if (roundStart && gameState.endRound())
		displayRewards(window, event);

}