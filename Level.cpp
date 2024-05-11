#include "Level.h"
#include "iostream"
Level::Level(int level, int numOfZombies, int plantOptions, int zombieOptions, int numOfRewards, int numOfChallenges, std::string* rewards, std::string* challenges, std::string name):level(level),numOfZombies(numOfZombies),waves(waves),plantOptions(plantOptions),zombieOptions(zombieOptions),numOfRewards(numOfRewards),numOfChallenges(numOfChallenges),rewards(rewards), challenges(challenges),name(name),roundStart(false),nextLevel(false),gameState(plantOptions,20) {
	waves = 3;
	font.loadFromFile("./SFML/Fonts/serio.ttf");
	challengesText = new sf::Text[numOfChallenges];
	for (int i = 0; i < numOfChallenges; i++) {
		challengesText[i].setFont(font);
		challengesText[i].setPosition(400, 200 + i * 50);
		button.setPosition(500, 300 + i * 100);
		challengesText[i].setString(challenges[i]);
		challengesText[i].setCharacterSize(15);
		challengesText[i].setFillColor(sf::Color::White);
	}
	rewardsText = new sf::Text[numOfRewards];
	for (int i = 0; i < numOfRewards; i++) {
		rewardsText[i].setFont(font);
		rewardsText[i].setPosition(400, 200 + i * 50);
		button.setPosition(500, 300 + i * 100);
		rewardsText[i].setString(rewards[i]);
		rewardsText[i].setCharacterSize(15);
		rewardsText[i].setFillColor(sf::Color::White);
	}
	buttonTexture.loadFromFile("./SFML/Images/startButton.png");
	button.setTexture(buttonTexture);
	button.setTextureRect(sf::IntRect(0, 0, 154, 37));
}

void Level::createBack(sf::RenderWindow& window) {
	//Drawing the background
	sf::Image map_image;
	map_image.loadFromFile("./SFML/Images/day.png");
	sf::Texture map;
	map.loadFromImage(map_image);
	sf::Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	if (!roundStart ||(roundStart && gameState.endRound()))
		s_map.setColor(sf::Color(255, 255, 255, 128));
	else 
		s_map.setColor(sf::Color(255, 255, 255, 255));
	window.draw(s_map);
}


void Level::displayChallenges(sf::RenderWindow& window,sf::Event event) {
	
	
	for (int i = 0; i < numOfChallenges; i++) {
		window.draw(challengesText[i]);	
	}
	window.draw(button);

	if (event.type == sf::Event::MouseButtonPressed) {
		sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		if (button.getGlobalBounds().contains(mouse)) {
			roundStart = true;
			int* numZombies = new int[3];
			numZombies[0] = 10;
			numZombies[1] = 7;
			numZombies[2] = 3;
			gameState.startRound(numZombies,3);
		}
			
	}

}
void Level::displayRewards(sf::RenderWindow& window, sf::Event event) {
	static sf::Text result;
	result.setFont(font);
	result.setCharacterSize(55);
	result.setPosition(300, 250);
	if (gameState.getLives() == 0) {
		result.setFillColor(sf::Color::Red);
		result.setString("YOU LOST");
	}
	else {
		result.setFillColor(sf::Color::Green);
		result.setString("YOU WON");
	for (int i = 0; i < numOfRewards; i++) {
		window.draw(rewardsText[i]);
	}
	}
	window.draw(result);
	

	

}
void Level::displayLevel(sf::RenderWindow& window, sf::Event event) {
	createBack(window);
	if (!roundStart)
		displayChallenges(window,event);
	if (roundStart && !gameState.endRound()) {
		gameState.gameplay(window, event);
		
	}
	else if (roundStart && gameState.endRound())
		displayRewards(window, event);
	
}