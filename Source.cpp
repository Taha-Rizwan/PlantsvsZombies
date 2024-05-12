﻿#include <iostream>
#include"headers.h"
#include <ctime>

//#include"../SFML/Images/"
using namespace sf;
using namespace std;

int x = 0;
int y = 1;


void createStart(sf::RenderWindow& window,sf::Font& font,float iconX) {
	//Start Screen Image
	Image sImage;
	sImage.loadFromFile("./SFML/Images/start.jpg");
	Texture start;
	start.loadFromImage(sImage);
	Sprite startScreen;
	startScreen.setTexture(start);
	startScreen.setPosition(0,0);
	startScreen.setScale(0.8, 0.55);

	//Loading bar
	sf::RectangleShape loadingBar(sf::Vector2f(800, 35));
	loadingBar.setPosition(290, 560);
	loadingBar.setFillColor(sf::Color::Black);
	Text loading;
	loading.setFont(font);
	loading.setCharacterSize(20);
	loading.setString("LOADING ....");
	loading.setPosition(640,563);
	Texture loadedTexture;
	loadedTexture.loadFromFile("./SFML/Images/green.jpg");\

	//Loaded part
	sf::RectangleShape loaded;
	loaded.setPosition(290, 560);
	float loadLength = iconX - loaded.getPosition().x;
	if (loadLength < 0) {
		loadLength = 0;
	}
	//Adjust size of the loaded part
	loaded.setSize(sf::Vector2f(loadLength,35)); 
	loaded.setTexture(&loadedTexture);
	loaded.setTextureRect(sf::IntRect(0, 0, loadLength, 35));

	//Draw 
	window.draw(startScreen);
	window.draw(loadingBar);
	window.draw(loaded);
	window.draw(loading);
}

void createPause(sf::RenderWindow& window) {
	sf::RectangleShape pauseScreen(sf::Vector2f(1200,600));
	pauseScreen.setPosition(0, 0);
	pauseScreen.setFillColor(sf::Color(0,0,0,150));
	window.draw(pauseScreen);
}


//For moving the zombie icon across the loading bar
bool moveIcon(Sprite& sprite, sf::Clock& mClock) {
	static bool moved = false;
	Time elapsed = mClock.getElapsedTime(); 

	if (!moved) {
		float speed = 60.0f; 

		float distance = speed * elapsed.asSeconds();

		if (sprite.getPosition().x + distance >= 1000) {
			sprite.setPosition(1000, sprite.getPosition().y);
			moved = true; 
		}
		else {
			sprite.move(distance, 0);
		}
	}
	return moved;
}

//Function that creates menuTexts and returns them
Menu createMenu(sf::RenderWindow& window,sf::Font& font) {
	
	Menu menuTexts;
	menuTexts.startText.setFont(font);
	menuTexts.startText.setString("START");
	menuTexts.startText.setCharacterSize(50);
	menuTexts.startText.setFillColor(sf::Color::White);
	menuTexts.startText.setPosition(670, 100);
	menuTexts.modeText= menuTexts.startText;
	menuTexts.modeText.setString("MODE");
	menuTexts.modeText.setPosition(670, 200);
	menuTexts.exitText = menuTexts.startText;
	menuTexts.exitText.setString("EXIT");
	menuTexts.exitText.setPosition(670, 300);
	menuTexts.resumeText = menuTexts.startText;
	menuTexts.resumeText.setString("RESUME");
	menuTexts.resumeText.setPosition(670, 100);
	menuTexts.mainMenuText = menuTexts.startText;
	menuTexts.mainMenuText.setString("BACK TO MAIN MENU");
	menuTexts.mainMenuText.setPosition(670, 200);
	return menuTexts;
}

//For moving the "HARD" text
void moveText(sf::Text& text, sf::RenderWindow& window){
	//Move text
	text.move(10.0,0);

	sf::FloatRect textBounds = text.getGlobalBounds();
	//Boundary Check(so it does not get out of the screen)
	if ((textBounds.left-150) > window.getSize().x) {
		text.setPosition(20, text.getPosition().y);
	}
}

//Event Handling
void handleEvents(sf::RenderWindow& window,sf::Event event,bool& startGame,bool& showMenu,bool& showModes,bool& pause,Menu menuTexts) {
	if (event.type == Event::Closed)
		window.close();
	//If text is clicked by mouse
	if (event.type == Event::MouseButtonPressed && startGame) {
		sf::Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
		if (menuTexts.startText.getGlobalBounds().contains(mouse) && (!pause && showMenu && !showModes)) {
			showMenu = false;
			showModes = false;
		}
		else if (menuTexts.modeText.getGlobalBounds().contains(mouse) && (showMenu && !showModes && !pause)) {
			showModes = true;
		}
		else if (menuTexts.exitText.getGlobalBounds().contains(mouse) && (showMenu && !pause && !showModes)) {
			window.close();
		}
		else if (menuTexts.backText.getGlobalBounds().contains(mouse)) {
			showMenu = true;
			showModes = false;
		}
		else if (menuTexts.easyText.getGlobalBounds().contains(mouse)) {

		}
		else if (menuTexts.hardText.getGlobalBounds().contains(mouse)) {
			//moves the hard text
			moveText(menuTexts.hardText, window);
		}
		else if (menuTexts.resumeText.getGlobalBounds().contains(mouse)&& pause) {
			pause = false;
		}
		else if (menuTexts.mainMenuText.getGlobalBounds().contains(mouse)&& pause) {
			pause = false;
			showMenu = true;
		}
	}
	if (event.type == Event::MouseMoved && startGame) {
		sf::Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
		if (menuTexts.startText.getGlobalBounds().contains(mouse) && (!pause && showMenu && !showModes)) {
			menuTexts.startText.setFillColor(sf::Color::Green);
			menuTexts.modeText.setFillColor(sf::Color::White);
			menuTexts.exitText.setFillColor(sf::Color::White);
			cout << "Start\n";

		}
		else if (menuTexts.modeText.getGlobalBounds().contains(mouse) && (!pause && showMenu && !showModes)) {
			menuTexts.modeText.setFillColor(sf::Color::Green);
			menuTexts.startText.setFillColor(sf::Color::White);
			menuTexts.exitText.setFillColor(sf::Color::White);
			cout << "Mode\n";

		}
		else if (menuTexts.exitText.getGlobalBounds().contains(mouse) && (!pause && showMenu && !showModes)) {
			menuTexts.exitText.setFillColor(sf::Color::Green);
			menuTexts.modeText.setFillColor(sf::Color::White);
			menuTexts.startText.setFillColor(sf::Color::White);
			cout << "Exit";
		}
		else if (menuTexts.easyText.getGlobalBounds().contains(mouse) && !pause && !showMenu) {
			menuTexts.easyText.setFillColor(sf::Color::Green);
			menuTexts.hardText.setFillColor(sf::Color::White);
			menuTexts.backText.setFillColor(sf::Color::White);
			cout << "Easy\n";
		}
		else if (menuTexts.hardText.getGlobalBounds().contains(mouse) && !pause && showModes) {
			moveText(menuTexts.hardText, window);
			menuTexts.easyText.setFillColor(sf::Color::White);
			menuTexts.backText.setFillColor(sf::Color::White);
			cout << "Hard\n";
		}
		else if (menuTexts.backText.getGlobalBounds().contains(mouse)&& !pause && showModes){
			menuTexts.backText.setFillColor(sf::Color::Green);
			menuTexts.easyText.setFillColor(sf::Color::White);
			menuTexts.hardText.setFillColor(sf::Color::White);
			cout << "Back\n";
		}
		else if (menuTexts.resumeText.getGlobalBounds().contains(mouse)) {
			menuTexts.resumeText.setFillColor(sf::Color::Green);
			menuTexts.mainMenuText.setFillColor(sf::Color::White);
		}
		else if (menuTexts.mainMenuText.getGlobalBounds().contains(mouse)) {
			menuTexts.resumeText.setFillColor(sf::Color::White);
			menuTexts.mainMenuText.setFillColor(sf::Color::Green);
		}
	}
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
		pause =!pause;
	}
}
//Drawing the background

//Drawing the map





int main()
{
	srand(time(0));
	//Create a window, n*n
	RenderWindow window(VideoMode(1400, 600), "Plants Vs Zombies"); //was (1400,600)
	//Game icon
	Image icon;
	if (!icon.loadFromFile("./SFML/Images/icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());
	Clock iconClock;

	//Main Menu Screen textures,sprites and fonts
	Texture menuTexture;
	menuTexture.loadFromFile("./SFML/Images/menu.jpg");
	Sprite menu;
	menu.setTexture(menuTexture);
	menu.setPosition(0, 0);
	menu.setScale(1.1, 1);
	Font font;
	font.loadFromFile("./SFML/Fonts/serio.ttf");
	Menu menuTexts = createMenu(window,font);
	menuTexts.startText.setPosition(670, 100);			
	menuTexts.modeText.setPosition(670, 200);
	menuTexts.exitText.setPosition(670, 300);
	//Modes menu screen texts
	menuTexts.backText=(menuTexts.startText);
	menuTexts.backText.setString("BACK");
	menuTexts.backText.setPosition(670,300);
	menuTexts.easyText=(menuTexts.startText);
	menuTexts.easyText.setString("EASY");
	menuTexts.easyText.setPosition(670, 100);
	menuTexts.hardText=(menuTexts.startText);
	menuTexts.hardText.setString("HARD");
	menuTexts.hardText.setPosition(670, 200);
	string* rewards, * challenges;
	rewards = new std::string[1];
	rewards[0] = "Unlocked Wallnut!";
	challenges = new std::string[2];
	challenges[0] = "Limited Plant Selection";
	challenges[1] = "Slow Zombie Waves";

	///////////////////////////////////////

	//Game field (5*9)
	//Point 137*79 - leftmost point
	//length 41; width 53
	const int ROWS = 5;
	const int COLS = 9;

	bool FIELD_GAME_STATUS[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			FIELD_GAME_STATUS[i][j] = true;
		}
	}
	Clock clock;
	Time timePerFrame = seconds(1.f / 60.f); // 60 FPS
	Level** levels= new Level * [4];
	levels[0] = new Level1();
	levels[1] = new Level2();
	levels[2] = new Level3();
	levels[3] = new Level4();
	int currentLevel = 0;
	
	//Y-axis starting point is 75, +100 to the slot below
	//X-axis starting point is 265, +80 to the slot on the right
	


	//If a bullet is shot it gets saved to the bullets array, and boom boom
	
	static bool startGame = true;
	static bool showMenu = false;//bool for showing menu
	static bool showModes = false;//bool for showing modes in menu
	static bool pause = false;

	



	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{

			handleEvents(window, event, startGame, showMenu, showModes, pause, menuTexts);
			sf::Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
			
		}
			//if mouse hovers over text
			window.clear();
			if (!startGame) {
				//Shows the start screen
				window.clear();
				Texture icon;
				icon.loadFromFile("./SFML/Images/icon2.png");
				Sprite sIcon;
				sIcon.setTexture(icon);
				sIcon.setPosition(230, 555);
				sIcon.setScale(0.18, 0.12);
				sIcon.setColor(sf::Color(255, 255, 255, 225));
				if (moveIcon(sIcon, iconClock)) {
					startGame = true;
					showMenu = true;
				}
				createStart(window,font, sIcon.getPosition().x + 35);
				window.draw(sIcon);
			}
			//Shows the menu
			else if (showMenu) {
				window.clear();
				window.draw(menu);
				if (showModes){
					//Shows modes
					window.draw(menuTexts.easyText);
					window.draw(menuTexts.hardText);
					window.draw(menuTexts.backText);
				}
				else {
					window.draw(menuTexts.startText);
					window.draw(menuTexts.modeText);
					window.draw(menuTexts.exitText);
				}
			}
			else if(!pause) {
				levels[currentLevel]->displayLevel(window, event,pause);
				if (currentLevel > 1 && levels[currentLevel - 1] != nullptr)
				{
					delete levels[currentLevel - 1];
					levels[currentLevel - 1] = nullptr;
				}

				if (levels[currentLevel]->levelOver() && currentLevel < 3)
				{
					currentLevel++;
				}
			}
			else if(pause){
				clock.restart();
				window.clear();
				window.draw(menu);
				window.draw(menuTexts.resumeText);
				window.draw(menuTexts.mainMenuText);
			}
		window.setSize(Vector2u(1100,680)); //was(1100,680)//
		window.display();
	}

	return 0;
}