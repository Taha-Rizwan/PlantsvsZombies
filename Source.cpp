
#include <iostream>
#include<fstream>
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

void handleInput(sf::Event& event,sf::Text& playerName) {
	if (event.type == sf::Event::TextEntered) {
		if (event.text.unicode < 128) {
			if (event.type==Event::KeyPressed && event.key.code==Keyboard::BackSpace) {
				std::string input = playerName.getString();
				input.pop_back();
				playerName.setString(input);
			}
			else if (event.text.unicode != 13) { 
				playerName.setString(playerName.getString() + static_cast<char>(event.text.unicode));
			}
		}
	}
}

//Takes input(player's name)
void createInputScreen(sf::RenderWindow& window,sf::Event& event,sf::Font& font,sf::Text& playerName) {

	sf::RectangleShape inputBox(sf::Vector2f(300, 40));
	inputBox.setPosition(550,280);
	inputBox.setFillColor(sf::Color::White);
	inputBox.setOutlineThickness(2);
	inputBox.setOutlineColor(sf::Color::Black);


	sf::Text inputPrompt;
	inputPrompt.setFont(font);
	inputPrompt.setCharacterSize(24);
	inputPrompt.setFillColor(sf::Color::Black);
	inputPrompt.setString("Player Name:");
	inputPrompt.setPosition(550, 240); 
	window.draw(inputPrompt);


	sf::RectangleShape cursor(sf::Vector2f(2, playerName.getCharacterSize()));
	cursor.setFillColor(sf::Color::Black);
	bool showCursor = true;

	sf::Clock cursorClock;
	if (cursorClock.getElapsedTime().asSeconds() > 0.5f) {
		showCursor = !showCursor;
		cursorClock.restart();
	}
	window.draw(inputBox);
	window.draw(inputPrompt);
	window.draw(playerName);
	if (showCursor && playerName.getString().getSize() < 20) {
		cursor.setPosition(playerName.getPosition().x + playerName.getGlobalBounds().width + 2,
			playerName.getPosition().y);
		window.draw(cursor);
	}
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
	menuTexts.exitText.setPosition(670, 400);
	menuTexts.pauseText = menuTexts.startText;
	menuTexts.pauseText.setString("GAME PAUSED");
	menuTexts.pauseText.setPosition(640, 250);
	menuTexts.mainMenuText = menuTexts.startText;
	menuTexts.mainMenuText.setString("BACK TO MAIN MENU");
	menuTexts.mainMenuText.setPosition(670, 200);

	menuTexts.highText = menuTexts.startText;
	menuTexts.highText.setString("High Scores");
	menuTexts.highText.setPosition(670, 300);
	
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
void handleEvents(sf::RenderWindow& window,sf::Event event,bool& startGame,bool& showMenu,bool& showModes,bool&showLevels,bool &showHigh,bool& pause,bool& input,Menu menuTexts, int& currentLevel) {
	if (event.type == Event::Closed)
		window.close();
	//If text is clicked by mouse
	if (event.type == Event::MouseButtonPressed && startGame) {
		sf::Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
		if (menuTexts.startText.getGlobalBounds().contains(mouse) && (!pause && showMenu && !showModes && !showLevels && !showHigh)) {
			showLevels = true;
			showModes = false;
		}
		else if (menuTexts.modeText.getGlobalBounds().contains(mouse) && (showMenu && !showModes && !pause && !showLevels && !showHigh)) {
			showModes = true;
		}
		else if (menuTexts.highText.getGlobalBounds().contains(mouse) && (showMenu && !showModes && !pause && !showLevels && !showHigh)) {
			showHigh = true;
			showModes = false;
		}
		else if (menuTexts.exitText.getGlobalBounds().contains(mouse) && (showMenu && !pause && !showModes && !showLevels && !showHigh)) {
			window.close();
		}
		else if (menuTexts.backText.getGlobalBounds().contains(mouse) && !showLevels && !showHigh) {
			showMenu = true;
			showModes = false;
		}
		else if (menuTexts.easyText.getGlobalBounds().contains(mouse) && !showLevels && !showHigh) {

		}
		else if (menuTexts.hardText.getGlobalBounds().contains(mouse) ) {
			//moves the hard text
			moveText(menuTexts.hardText, window);
		}
		else if (menuTexts.pauseText.getGlobalBounds().contains(mouse)&& pause && !showLevels && !showHigh) {
			pause = false;
		}
		else if (menuTexts.mainMenuText.getGlobalBounds().contains(mouse)&& pause && !showLevels && !showHigh) {
			pause = false;
			showMenu = true;
		}
		else if (menuTexts.level1Text.getGlobalBounds().contains(mouse) && (showMenu && !showModes && !pause && showLevels && !showHigh)) {
			showModes = false;
			showLevels = false;
			showMenu = false;
			currentLevel = 0;
		}
		else if (menuTexts.level2Text.getGlobalBounds().contains(mouse) && (showMenu && !showModes && !pause && showLevels && !showHigh)) {
			showModes = false;
			showLevels = false;
			showMenu = false;
			currentLevel = 1;
		}
		else if (menuTexts.level3Text.getGlobalBounds().contains(mouse) && (showMenu && !showModes && !pause && showLevels && !showHigh)) {
			showModes = false;
			showLevels = false;
			showMenu = false;
			currentLevel = 2;
		}
		else if (menuTexts.level4Text.getGlobalBounds().contains(mouse) && (showMenu && !showModes && !pause && showLevels && !showHigh)) {
			showModes = false;
			showLevels = false;
			showMenu = false;
			currentLevel = 3;
		}
		else if (menuTexts.menuBackText.getGlobalBounds().contains(mouse) && (showMenu && !showModes && !pause && showLevels && !showHigh)) {
			showModes = false;
			showLevels = false;
			showMenu = true;
			currentLevel = 0;
		}
		else if (menuTexts.highBackText.getGlobalBounds().contains(mouse) && (showMenu && !showModes && !pause && !showLevels )) {
			showModes = false;
			showLevels = false;
			showHigh = false;
			showMenu = true;
			currentLevel = 0;
		}
	}
	if (event.type == Event::MouseMoved && startGame) {
		sf::Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
		if (menuTexts.startText.getGlobalBounds().contains(mouse) && (!pause && showMenu && !showModes && !input)) {
			menuTexts.startText.setFillColor(sf::Color::Green);
			menuTexts.modeText.setFillColor(sf::Color::White);
			menuTexts.exitText.setFillColor(sf::Color::White);

		}
		else if (menuTexts.modeText.getGlobalBounds().contains(mouse) && (!pause && showMenu && !showModes && !input)) {
			menuTexts.modeText.setFillColor(sf::Color::Green);
			menuTexts.startText.setFillColor(sf::Color::White);
			menuTexts.exitText.setFillColor(sf::Color::White);

		}
		else if (menuTexts.exitText.getGlobalBounds().contains(mouse) && (!pause && showMenu && !showModes && !input)) {
			menuTexts.exitText.setFillColor(sf::Color::Green);
			menuTexts.modeText.setFillColor(sf::Color::White);
			menuTexts.startText.setFillColor(sf::Color::White);
		}
		else if (menuTexts.easyText.getGlobalBounds().contains(mouse) && !pause && !showMenu && !input) {
			menuTexts.easyText.setFillColor(sf::Color::Green);
			menuTexts.hardText.setFillColor(sf::Color::White);
			menuTexts.backText.setFillColor(sf::Color::White);
		}
		else if (menuTexts.hardText.getGlobalBounds().contains(mouse) && !pause && showModes && !input) {
			moveText(menuTexts.hardText, window);
			menuTexts.easyText.setFillColor(sf::Color::White);
			menuTexts.backText.setFillColor(sf::Color::White);
		}
		else if (menuTexts.backText.getGlobalBounds().contains(mouse)&& !pause && showModes && !input){
			menuTexts.backText.setFillColor(sf::Color::Green);
			menuTexts.easyText.setFillColor(sf::Color::White);
			menuTexts.hardText.setFillColor(sf::Color::White);
		}

	}
	if (event.type == Event::KeyPressed) {
		if(event.key.code == Keyboard::Escape)
			pause =!pause;
		else if (event.key.code == Keyboard::Enter/* && input */ ) {
			input = false;
			showMenu = true;
		}
	}

}

//Read from the high scores File
void readFile(HighScore* highscores) {
	ifstream file("./highscores.txt");
	if (file.is_open()) {
		
		for (int i = 0; i < 4; i++) {
			if (file.eof())
				break;
			file >> highscores[i].playerName >> highscores[i].score;
		}
		file.close();
	}
	else {
		cout << "Error opening file\n";
	}
}

//Write In File
void writeFile(HighScore* highscores) {
	ofstream file("./highscores.txt");
	if (file.is_open()) {
		for (int i = 0; i < 4; i++) {
			if (highscores[i].score == 0)
				break;
			file << highscores[i].playerName + "\n" << highscores[i].score;
		}
		file.close();
	}
	else {
		cout << "Error opening file\n";
	}
}





int main()
{
	//Highscores
	HighScore highscores[4];
	readFile(highscores);

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
	//Levels Menu Screen
	menuTexts.level1Text = (menuTexts.startText);
	menuTexts.level1Text.setString("Beginner's Garden");
	menuTexts.level1Text.setPosition(570, 100);
	menuTexts.level2Text = (menuTexts.startText);
	menuTexts.level2Text.setString("Zombie OutSkirts");
	menuTexts.level2Text.setPosition(570, 200);
	menuTexts.level3Text = (menuTexts.startText);
	menuTexts.level3Text.setString("Sunflower Fields");
	menuTexts.level3Text.setPosition(570, 300);
	menuTexts.level4Text = (menuTexts.startText);
	menuTexts.level4Text.setString("Foggy Forest");
	menuTexts.level4Text.setPosition(570, 400);
	menuTexts.menuBackText = (menuTexts.startText);
	menuTexts.menuBackText.setString("BACK");
	menuTexts.menuBackText.setPosition(570, 500);
	menuTexts.highBackText = (menuTexts.startText);
	menuTexts.highBackText.setString("BACK");
	menuTexts.highBackText.setPosition(570, 500);
	for (int i = 0; i < 4; i++) {
		if (highscores[i].playerName.empty())
			break;
		menuTexts.highScores[i] = menuTexts.startText;
		menuTexts.highScores[i].setString(highscores[i].playerName +": "+to_string(highscores[i].score));
		menuTexts.highScores[i].setPosition(550, 100 * (i + 1));
	}
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




	Music mainMenu;
	mainMenu.openFromFile("./SFML/Music/mainMenu.mp3");
	//Y-axis starting point is 75, +100 to the slot below
	//X-axis starting point is 265, +80 to the slot on the right
	


	//If a bullet is shot it gets saved to the bullets array, and boom boom
	
	static bool startGame = false;
	static bool input = false;
	static bool showMenu = false;//bool for showing menu
	static bool showScores = false;
	static bool showModes = false;//bool for showing modes in menu
	static bool pause = false;
	static bool showLevels = false;
	static bool showHigh = false;

	sf::Text playerName;
	playerName.setFont(font);
	playerName.setPosition(550, 280);
	playerName.setCharacterSize(24);
	playerName.setFillColor(sf::Color::Black);
	playerName.setString("");

	int currentScore = 0;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
handleEvents(window, event, startGame, showMenu, showModes,showLevels,showHigh, pause,input,menuTexts,currentLevel);
			if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode < 128) {
					if (event.type == Event::KeyPressed && event.key.code == Keyboard::BackSpace) {
						std::string input = playerName.getString();
						input.pop_back();
						playerName.setString(input);
					}
					else if (event.text.unicode != 13) {
						playerName.setString(playerName.getString() + static_cast<char>(event.text.unicode));
					}
				}
			}
		}
			//if mouse hovers over text
			window.clear();
			if (!startGame) {
				//Shows the start screen
				if (mainMenu.getStatus() == SoundSource::Status::Stopped)
				mainMenu.play();
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
					input = true;
				}
				createStart(window,font, sIcon.getPosition().x + 35);
				window.draw(sIcon);
			}
			else if (input) {
				window.clear();
				window.draw(menu);
				createInputScreen(window, event,font, playerName);
				//showMenu=true;
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
				else if (showLevels) {
					window.draw(menuTexts.level1Text);
					window.draw(menuTexts.level2Text);
					window.draw(menuTexts.level3Text);
					window.draw(menuTexts.level4Text);
					window.draw(menuTexts.menuBackText);
				}
				else if (showHigh) {
					for (int i = 0; i < 4; i++) {
					
						
							if (i >= 1 && highscores[i].score == highscores[i - 1].score && highscores[i].playerName == highscores[i - 1].playerName) {

							}
							else { 
								window.draw(menuTexts.highScores[i]); 
							}
						
						
					}
					window.draw(menuTexts.highBackText);
				}
				else {
					window.draw(menuTexts.startText);
					window.draw(menuTexts.modeText);
					window.draw(menuTexts.exitText);
					window.draw(menuTexts.highText);

				}
			}
			else if(!pause) {
				if (mainMenu.getStatus() == SoundSource::Status::Playing)
					mainMenu.stop();
				levels[currentLevel]->displayLevel(window, event,pause,currentScore);
				if (currentLevel > 1 && levels[currentLevel - 1] != nullptr)
				{
					delete levels[currentLevel - 1];
					levels[currentLevel - 1] = nullptr;
				}

				if (levels[currentLevel]->levelOver() && currentLevel < 3)
				{
					currentLevel++;
				}
				sf::RectangleShape scoreBar(sf::Vector2f(200, 75));
				scoreBar.setFillColor(sf::Color(0,0,0,150));
				scoreBar.setPosition(950,3);
				scoreBar.setOutlineColor(sf::Color::White);
				scoreBar.setOutlineThickness(1);

				std::string scoreString = "Score: " + std::to_string(currentScore);
				sf::Text score = playerName;
				score.setCharacterSize(34);
				score.setFillColor(sf::Color::White);
				score.setString(scoreString);
				score.setPosition(960, 20);
				window.draw(scoreBar);
				window.draw(score);
			}
			else if(pause){
				mainMenu.play();
				clock.restart();
				window.clear();
				window.draw(menu);
				window.draw(menuTexts.pauseText);
			}
		window.setSize(Vector2u(1100,680)); //was(1100,680)//
		window.display();



	}
	for (int i = 0; i < 4; i++) {
		if (currentScore == 0)
			break;
		if (currentScore > highscores[i].score) {
			string name = playerName.getString();
			highscores[i].playerName = name;
			highscores[i].score = currentScore;
			break;
		}
	}
	writeFile(highscores);
	return 0;
}