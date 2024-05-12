#include "Level2.h"
#include "iostream"
Level2::Level2() : Level(2, 20, 4, 4, "Zombie Outskirts","Cherry Bomb Unlocked","Faster Zombie Waves","Limited Resources") {
	levelMusic.openFromFile("./SFML/Music/2.mp3");
	levelMusic.setLoop(true);
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
	if (!roundStart || (roundStart && gameState.endLevel()))
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
			int* numZombies = new int[2];
			numZombies[0] = 3;
			numZombies[1] = 2;
			
			levelMusic.play();
			gameState.startRound(numZombies, 2);
		}
	}

}
void Level2::displayLevel(sf::RenderWindow& window, sf::Event event,bool state,int& score) {
	createBack(window);
	if (!roundStart)
		displayChallenges(window, event);
	if (roundStart && !gameState.endLevel()) {
		gameState.gameplay(window, event,state,score);
		if (gameState.endRound()) {
			waves++;
			if (waves == 1) {
				int* numZombies = new int[3];
				numZombies[0] = 3;
				numZombies[1] = 2;
				numZombies[2] = 2;
				gameState.startRound(numZombies, 3);
			}
			else if (waves == 2) {
				int* numZombies = new int[4];
				numZombies[0] = 2;
				numZombies[1] = 2;
				numZombies[2] = 2;
				numZombies[3] = 2;
				gameState.startRound(numZombies, 4);

			}
			waveClock.restart();
		}
		displayWave(window);

	}
	else if (roundStart && gameState.endLevel())
	{
		if (levelMusic.getStatus() == sf::SoundSource::Status::Playing)
			levelMusic.stop();
		displayRewards(window, event);

	}
}