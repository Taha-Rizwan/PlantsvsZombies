/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/

#pragma once
#include<SFML/Graphics.hpp>
class Menu {
public:
	//Menu class which has all the menu texts
	sf::Text startText;
	sf::Text modeText;
	sf::Text highText;
	sf::Text highScores[4];
	sf::Text exitText;
	sf::Text easyText;
	sf::Text hardText;
	sf::Text backText;
	sf::Text menuBackText;
	sf::Text highBackText;
	sf::Text pauseText;
	sf::Text mainMenuText;
	sf::Text level1Text;
	sf::Text level2Text;
	sf::Text level3Text;
	sf::Text level4Text;
};