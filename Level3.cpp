#include "Level3.h"
#include "iostream"
Level3::Level3() : Level(3, 25, 5, 4, "Sunflower Fields","Repeater Unlocked","Limited PLacement for plants","Focus on Sunflower", true) {

}

void Level3::createBack(sf::RenderWindow& window) {
	//Drawing the background
	sf::Image map_image;
	map_image.loadFromFile("./SFML/Images/limitedbg.jpg");
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

void Level3::displayChallenges(sf::RenderWindow& window, sf::Event event) {



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
			numZombies[0] = 12;
			numZombies[1] = 8;
			numZombies[2] = 3;
			numZombies[3] = 2;

			gameState.startRound(numZombies, numOfZombies);
		}
	}

}
void Level3::displayLevel(sf::RenderWindow& window, sf::Event event) {
	createBack(window);
	if (!roundStart)
		displayChallenges(window, event);
	if (roundStart && !gameState.endRound()) {
		gameState.gameplay(window, event);

	}
	else if (roundStart && gameState.endRound())
		displayRewards(window, event);
}