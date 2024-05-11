#include"Level.h"
#include "iostream"
Level::Level(int level, int numOfZombies, int plantOptions, int zombieOptions, std::string name, std::string rewards, std::string challenges1, std::string challenges2, bool limited ) :level(level),numOfZombies(numOfZombies),plantOptions(plantOptions),zombieOptions(zombieOptions),rewards(rewards),name(name),gameState(plantOptions,numOfZombies,limited),nextLevel(false),roundStart(false) {
	challenges[0] = challenges1;
	challenges[1] = challenges2;
	waves = 3;
	challengesText = new sf::Text[2];
	font.loadFromFile("./SFML/Fonts/serio.ttf");
	for (int i = 0; i < 2; i++) {
		challengesText[i].setFont(font);
		challengesText[i].setPosition(400, 200 + i * 50);
		button.setPosition(500, 300 + i * 100);
		challengesText[i].setString(challenges[i]);
		challengesText[i].setCharacterSize(15);
		challengesText[i].setFillColor(sf::Color::White);
	}
	rewardsText = new sf::Text[1];
		rewardsText->setFont(font);
		rewardsText->setPosition(400, 200);
		nextButton.setPosition(500, 400);
		rewardsText->setString(rewards);
		rewardsText->setCharacterSize(15);
		rewardsText->setFillColor(sf::Color::White);

	nameText.setFont(font);
	nameText.setPosition(350, 100);;
	nameText.setString(name);
	nameText.setCharacterSize(55);
	nameText.setFillColor(sf::Color::Magenta);
	buttonTexture.loadFromFile("./SFML/Images/startButton.png");
	button.setTexture(buttonTexture);
	button.setTextureRect(sf::IntRect(0, 0, 922, 222));
	button.setScale(0.166, 0.166);
	nextButtonTexture.loadFromFile("./SFML/Images/nextbutton.png");
	nextButton.setTexture(nextButtonTexture);
	nextButton.setTextureRect(sf::IntRect(0, 0, 922, 222));
	nextButton.setScale(0.166, 0.166);
}



bool Level::levelOver() {
	return nextLevel;
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

			window.draw(*rewardsText);
			window.draw(nextButton);
			if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				if (nextButton.getGlobalBounds().contains(mouse)) {
					nextLevel = true;
					
				}
			}
	}
	window.draw(result);




}