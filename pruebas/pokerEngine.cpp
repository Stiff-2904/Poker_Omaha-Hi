#include "pokerEngine.h"
#include "safeFiles.h"

const string FOLDER_NAME = "gameFile";
const string FILE_NAME = "PokerGame.txt";
sf::RenderWindow window(sf::VideoMode(1280, 720), "POKER");
sf::Texture backgroundMenuFile, backgroundPlayersFile, backgroundGameFile, backgroundAboutFile;
sf::Sprite backgroundMenu, backgroundPlayer, backgroundGame, backgroundAbout;
sf::Font font1, font2, font3;
sf::Vector2i mousePos;
sf::Event gameLoop, gamePlay;
int sizePlayers = 0;
Button playButton, aboutButton, exitButton;

void loopRefresh() {

    while (window.pollEvent(gameLoop)) {
        if (gameLoop.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void startMenu() {

    backgroundMenuFile.loadFromFile("Textures/background_black1.png");
    backgroundPlayersFile.loadFromFile("Textures/background_players.png");
    backgroundMenu.setTexture(backgroundMenuFile);
    backgroundPlayer.setTexture(backgroundPlayersFile);
    font1.loadFromFile("Fonts/texas_font.otf");

    sf::Text menuPoker("MENU POKER", font1, 100);
    menuPoker.setPosition(300, 50);

    playButton.setShapeSize(250, 70);
    playButton.setText("Play");
    playButton.addFillColorText(sf::Color::Black);
    playButton.addFontText(font1);
    playButton.setShapePosition((1280 - playButton.getSize().x) / 2, 200); //resta el ancho del boton a la mitad del ancho de la ventana
    playButton.setTextPosition((1280 - playButton.getSize().x) / 2, 200);

    aboutButton.setShapeSize(250, 70);
    aboutButton.setText("About");
    aboutButton.addFillColorText(sf::Color::Black);
    aboutButton.addFontText(font1);
    aboutButton.setShapePosition((1280 - aboutButton.getSize().x) / 2, 350);
    aboutButton.setTextPosition((1280 - aboutButton.getSize().x) / 2, 350);

    exitButton.setShapeSize(250, 70);
    exitButton.setText("Exit");
    exitButton.addFillColorText(sf::Color::Black);
    exitButton.addFontText(font1);
    exitButton.setShapePosition((1280 - exitButton.getSize().x) / 2, 500);
    exitButton.setTextPosition((1280 - exitButton.getSize().x) / 2, 500);

    while (window.isOpen()) {
        loopRefresh();
        window.draw(backgroundMenu);
        window.draw(menuPoker);
        playButton.drawMe(window);
        aboutButton.drawMe(window);
        exitButton.drawMe(window);
        window.display();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            mousePos = sf::Mouse::getPosition(window);
            if (playButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                numOfPlayers();
            }
            else if (aboutButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                aboutWindow();
            }
            else if (exitButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                window.close();
            }
        }
    }
}

void aboutWindow() {

	backgroundAboutFile.loadFromFile("Textures/background_about.jpg");
	backgroundAbout.setTexture(backgroundAboutFile);
	font1.loadFromFile("Fonts/texas_font.otf");

	sf::Text AboutTitle("About", font1, 100);
	AboutTitle.setPosition(90, 50);

	Button menuButton, exitButton;

	menuButton.setShapeSize(200, 70);
	menuButton.setFillColorShape(sf::Color::Black);
	menuButton.setText("Menu");
	menuButton.addFillColorText(sf::Color::White);
	menuButton.addFontText(font1);
	menuButton.setShapePosition(980, 50);
	menuButton.setTextPosition(980, 50);

	exitButton.setShapeSize(200, 70);
	exitButton.setFillColorShape(sf::Color::Black);
	exitButton.setText("Exit");
	exitButton.addFillColorText(sf::Color::White);
	exitButton.addFontText(font1);
	exitButton.setShapePosition(980, 610);
	exitButton.setTextPosition(980, 610);

	while (window.isOpen()) {
		loopRefresh();
		window.draw(backgroundAbout);
		window.draw(AboutTitle);
		menuButton.drawMe(window);
		exitButton.drawMe(window);
		window.display();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			mousePos = sf::Mouse::getPosition(window);
			if (menuButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				startMenu();
				loopRefresh();
			}
			else if (exitButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				window.close();
			}
		}
	}
}

void numOfPlayers() {

    Button button2, button3, button4, button5, button6;
    font2.loadFromFile("Fonts/chopic_font.ttf");

    sf::Text choosePlayers("Choose the number of players", font1, 50);
    choosePlayers.setPosition(165, 200);

    exitButton.setShapeSize(200, 70);
    exitButton.setFillColorShape(sf::Color::Black);
    exitButton.setText("Exit");
    exitButton.addFillColorText(sf::Color::White);
    exitButton.addFontText(font1);
    exitButton.setShapePosition(980, 610);
    exitButton.setTextPosition(980, 610);

    button2.setShapeSize(170, 170);
    button2.setFillColorShape(sf::Color::Black);
    button2.setText("2");
    button2.addFillColorText(sf::Color::White);
    button2.addFontText(font2);
    button2.addLetterSize(168);
    button2.setShapePosition((1280 - 1200), 350);
    button2.setTextPosition((1280 - 1200), 305);

    button3.setShapeSize(170, 170);
    button3.setFillColorShape(sf::Color::Black);
    button3.setText("3");
    button3.addFillColorText(sf::Color::White);
    button3.addFontText(font2);
    button3.addLetterSize(168);
    button3.setShapePosition((1280 - 980), 350);
    button3.setTextPosition((1280 - 980), 305);

    button4.setShapeSize(170, 170);
    button4.setFillColorShape(sf::Color::Black);
    button4.setText("4");
    button4.addFillColorText(sf::Color::White);
    button4.addFontText(font2);
    button4.addLetterSize(168);
    button4.setShapePosition((1280 - 750), 350);
    button4.setTextPosition((1280 - 750), 305);

    button5.setShapeSize(170, 170);
    button5.setFillColorShape(sf::Color::Black);
    button5.setText("5");
    button5.addFillColorText(sf::Color::White);
    button5.addFontText(font2);
    button5.addLetterSize(168);
    button5.setShapePosition((1280 - 500), 350);
    button5.setTextPosition((1280 - 500), 305);

    button6.setShapeSize(170, 170);
    button6.setFillColorShape(sf::Color::Black);
    button6.setText("6");
    button6.addFillColorText(sf::Color::White);
    button6.addFontText(font2);
    button6.addLetterSize(168);
    button6.setShapePosition((1280 - 250), 350);
    button6.setTextPosition((1280 - 250), 305);

    while (window.isOpen()) {
        loopRefresh();
        window.draw(backgroundPlayer);
        window.draw(choosePlayers);
        button2.drawMe(window);
        button3.drawMe(window);
        button4.drawMe(window);
        button5.drawMe(window);
        button6.drawMe(window);
        exitButton.drawMe(window);
        window.display();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            mousePos = sf::Mouse::getPosition(window);

            if (exitButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                window.close();
            }
            if (button2.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                sizePlayers = 2;
                game();
            }
			if (button3.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                sizePlayers = 3;
				game();
			}
			if (button4.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                sizePlayers = 4;
				game();
			}
			if (button5.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                sizePlayers = 4;
				game();
			}
			if (button6.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                sizePlayers = 6;
				game(); 
			}
        }
    }
}

void game() {

	int betAmount = 0, i = 0, counterRounds = 1, counterPlayerRounds = 1, counterPlayerLeave = sizePlayers;
	bool startGame = false, showNeedToBetMessage = false;
	Button increaseBetButton, decreaseBetButton, allInButton, nextButton, leaveButton, enterButton;
	ListPlayer listPlayer(sizePlayers);
	Dealer dealer;
	Node* node = listPlayer.getHead();
	Player* playerAux = node->getPlayer();
	Player* winner;
	PokerCard cardCommu, cardComu1, cardComu2, cardComu3, cardComu4, cardComu5, card, card1, card2, card3, card4;
	SafeFiles file;

	ifstream checkFile(FOLDER_NAME + "/" + FILE_NAME);
	if (!checkFile) {
		file.createRegisterFile();
	}
	else {
		checkFile.close();
		file.createNewGame();
	}

	font3.loadFromFile("Fonts/limon_font3.otf");
	backgroundGameFile.loadFromFile("Textures/background_game3.png");
	backgroundGame.setTexture(backgroundGameFile);

	dealer.fillDeck();
	dealer.deckShufle();
	dealer.fillCommunityCards();
	listPlayer.fillAllHandsOfPlayers(dealer, sizePlayers);

	int x = 0;
	card = playerAux->getCardsInHand(x);
	card1 = card;
	card = playerAux->getCardsInHand(x + 1);
	card2 = card;
	card = playerAux->getCardsInHand(x + 2);
	card3 = card;
	card = playerAux->getCardsInHand(x + 3);
	card4 = card;

	card1.setPosition(135 + 50, 450);
	card2.setPosition(390 + 50, 450);
	card3.setPosition(645 + 50, 450);
	card4.setPosition(900 + 50, 450);
	card1.setShapeSize(150, 225);
	card2.setShapeSize(150, 225);
	card3.setShapeSize(150, 225);
	card4.setShapeSize(150, 225);

	int positionCardCommun = 0;
	cardCommu = dealer.getCommunityCards(positionCardCommun);
	cardComu1 = cardCommu;
	cardCommu = dealer.getCommunityCards(positionCardCommun + 1);
	cardComu2 = cardCommu;
	cardCommu = dealer.getCommunityCards(positionCardCommun + 2);
	cardComu3 = cardCommu;
	cardCommu = dealer.getCommunityCards(positionCardCommun + 3);
	cardComu4 = cardCommu;
	cardCommu = dealer.getCommunityCards(positionCardCommun + 4);
	cardComu5 = cardCommu;

	cardComu1.setShapeSize(140, 190);
	cardComu1.setPosition(220 + 20, 150);
	cardComu2.setShapeSize(140, 190);
	cardComu2.setPosition(385 + 20, 150);
	cardComu3.setShapeSize(140, 190);
	cardComu3.setPosition(550 + 20, 150);
	cardComu4.setShapeSize(140, 190);
	cardComu4.setPosition(710 + 20, 150);
	cardComu5.setShapeSize(140, 190);
	cardComu5.setPosition(865 + 20, 150);

	increaseBetButton.setShapeSize(90, 60);
	increaseBetButton.setFillColorShape(sf::Color::White);
	increaseBetButton.setText("+10");
	increaseBetButton.addFillColorText(sf::Color::Black);
	increaseBetButton.addFontText(font3);
	increaseBetButton.addLetterSize(35);
	increaseBetButton.setShapePosition(30, 250);
	increaseBetButton.setTextPosition(30, 250);

	decreaseBetButton.setShapeSize(90, 60);
	decreaseBetButton.setFillColorShape(sf::Color::White);
	decreaseBetButton.setText("-10");
	decreaseBetButton.addFillColorText(sf::Color::Black);
	decreaseBetButton.addFontText(font3);
	decreaseBetButton.addLetterSize(35);
	decreaseBetButton.setShapePosition(30, 350);
	decreaseBetButton.setTextPosition(30, 350);

	nextButton.setShapeSize(100, 60);
	nextButton.setFillColorShape(sf::Color::White);
	nextButton.setText("NEXT");
	nextButton.addFillColorText(sf::Color::Black);
	nextButton.addFontText(font3);
	nextButton.addLetterSize(20);
	nextButton.setShapePosition(1150, 250);
	nextButton.setTextPosition(1150, 250);

	leaveButton.setShapeSize(100, 60);
	leaveButton.setFillColorShape(sf::Color::White);
	leaveButton.setText("LEAVE");
	leaveButton.addFillColorText(sf::Color::Black);
	leaveButton.addFontText(font3);
	leaveButton.addLetterSize(20);
	leaveButton.setShapePosition(1150, 350);
	leaveButton.setTextPosition(1150, 350);

	enterButton.setShapeSize(100, 60);
	enterButton.setFillColorShape(sf::Color::White);
	enterButton.setText("ENTER");
	enterButton.addFillColorText(sf::Color::Black);
	enterButton.addFontText(font3);
	enterButton.addLetterSize(20);
	enterButton.setShapePosition(1150, 150);
	enterButton.setTextPosition(1150, 150);

	sf::Text token("Token: 100", font3, 30);
	token.setFillColor(sf::Color::White);
	token.setPosition(30, 10);

	sf::Text needToBet("You have to Bet", font3, 30);
	needToBet.setFillColor(sf::Color::White);
	needToBet.setPosition(500, 370);

	sf::Text winnerText("Winner ", font2, 100);
	winnerText.setFillColor(sf::Color::White);
	winnerText.setPosition(400, 200);

	sf::Text potText("Pot: 0", font3, 30);
	potText.setFillColor(sf::Color::White);
	potText.setPosition(1100, 10);     
	
	sf::Text namePlayerText("Player 1", font2, 100);
	namePlayerText.setFillColor(sf::Color::White);
	namePlayerText.setPosition(400, 10);

	sf::Text currentBet("Current bet: 0", font3, 30);
	currentBet.setFillColor(sf::Color::White);
	currentBet.setPosition(30, 50);

	while (window.isOpen()) {

		if (counterPlayerLeave == 1){
			window.close();
		}

		if (counterRounds == 5) {
			int i = 0;
			node = listPlayer.getHead();
			playerAux = node->getPlayer();
			while(i < sizePlayers){
				dealer.saveScore(playerAux);
				node = node->getNext();
				playerAux = node->getPlayer();
				i++;
			}
			node = listPlayer.getHead();
			playerAux = node->getPlayer();
			winner = playerAux;

			int j = 0;
			while(j < sizePlayers){
				node = node->getNext();
				playerAux = node->getPlayer();
				if (playerAux->getScore() > winner->getScore()) {
					winner = playerAux;
				}
				j++;
			}
			winnerText.setString("Winner!\n" + winner->getNamePlayer());
			window.clear();
			window.draw(backgroundMenu);
			window.draw(winnerText);
			window.display();
			file.writeMessage("WINNER!", winner->getPositionPlayer(), -1, 'W');
			loopRefresh();
		}

		else {
			if (!startGame) {
				file.writeMessage("Game started\n", -1, -1, 'R');
				file.writeMessage("Players on the table\n", sizePlayers, -1, 'P');
				startGame = true;
			}

			loopRefresh();
			window.draw(backgroundGame);
			card1.drawMe(window);
			card2.drawMe(window);
			card3.drawMe(window);
			card4.drawMe(window);

			if (counterRounds >= 2) {
				cardComu1.drawMe(window);
				cardComu2.drawMe(window);
				cardComu3.drawMe(window);
			}

			if (counterRounds >= 3) {
				cardComu4.drawMe(window);
			}
			if (counterRounds >= 4) {
				cardComu5.drawMe(window);
			}

			nextButton.drawMe(window);
			leaveButton.drawMe(window);
			allInButton.drawMe(window);
			increaseBetButton.drawMe(window);
			decreaseBetButton.drawMe(window);

			if (!playerAux->getIsPlaying()) {
				enterButton.drawMe(window);
			}
			if (showNeedToBetMessage) {
				window.draw(needToBet);
			}

			window.draw(token);
			window.draw(currentBet);
			window.draw(potText);
			window.draw(namePlayerText);
			window.display();

			while (window.pollEvent(gamePlay)) {
				if (gamePlay.type == sf::Event::Closed) {
					window.close();
				}
				if (gamePlay.type == sf::Event::MouseButtonPressed && gamePlay.mouseButton.button == sf::Mouse::Left) {
					mousePos = sf::Mouse::getPosition(window);

					if (increaseBetButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						playerAux->setIsBet(true);
						playerAux->increaseCurrentBet(10);
						currentBet.setString("Current bet: " + std::to_string(playerAux->getCurrentBet()));
						token.setString("Token: " + std::to_string(playerAux->getToken()));
						showNeedToBetMessage = false;
						window.draw(currentBet);
						window.draw(token);
						window.display();
					}
					if (decreaseBetButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						playerAux->decreaseCurrentBet(10);
						currentBet.setString("Current bet: " + std::to_string(playerAux->getCurrentBet()));
						token.setString("Token: " + std::to_string(playerAux->getToken()));
						showNeedToBetMessage = false;
						window.draw(currentBet);
						window.draw(token);
						window.display();
					}
					if (nextButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						file.writeMessage("Has the turn ", playerAux->getPositionPlayer(), -1, 'T');

						if (playerAux->getToken() == 0 && playerAux->getCurrentBet() == 0) {
							needToBet.setString("You don't have enough token!");
						}
						else {
							if (playerAux->getCurrentBet() == 0) {
								needToBet.setString("You have to bet!");
								showNeedToBetMessage = true;
							}
							else {
								if (counterRounds == 1 && counterPlayerRounds == 2) {
									dealer.setBigBlind(playerAux->getCurrentBet());
								}
								dealer.checkingRounds(counterPlayerRounds, counterRounds, sizePlayers);

								playerAux->betIncrease(dealer);
								file.writeMessage("bet", playerAux->getPositionPlayer(), playerAux->getCurrentBet(), 'B');
								playerAux->setCurrentBet(0);
								potText.setString("Pot: " + std::to_string(dealer.getPot()));
								currentBet.setString("Current bet: " + std::to_string(playerAux->getCurrentBet()));
								node = node->getNext();
								playerAux = node->getPlayer();
								playerAux->setIsBet(false);

								card = playerAux->getCardsInHand(i);
								card1.setTextureCard(card.getImageNumber());
								card = playerAux->getCardsInHand(i + 1);
								card2.setTextureCard(card.getImageNumber());
								card = playerAux->getCardsInHand(i + 2);
								card3.setTextureCard(card.getImageNumber());
								card = playerAux->getCardsInHand(i + 3);
								card4.setTextureCard(card.getImageNumber());

								namePlayerText.setString(playerAux->getNamePlayer());
								token.setString("Token: " + std::to_string(playerAux->getToken()));
							}
						}
					}
					if (leaveButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {

						file.writeMessage("Left the game", playerAux->getPositionPlayer(), -1, 'O');
						showNeedToBetMessage = false;
						playerAux->setCurrentBet(0);
						currentBet.setString("Current bet: " + std::to_string(playerAux->getCurrentBet()));
						playerAux->setIsPlaying(false);

						if (!playerAux->getIsPlaying()) {
							counterPlayerLeave--;
						}
						node = node->getNext();
						playerAux = node->getPlayer();

						card = playerAux->getCardsInHand(i);
						card1.setTextureCard(card.getImageNumber());
						card = playerAux->getCardsInHand(i + 1);
						card2.setTextureCard(card.getImageNumber());
						card = playerAux->getCardsInHand(i + 2);
						card3.setTextureCard(card.getImageNumber());
						card = playerAux->getCardsInHand(i + 3);
						card4.setTextureCard(card.getImageNumber());

						namePlayerText.setString(playerAux->getNamePlayer());
						token.setString("Token: " + std::to_string(playerAux->getToken()));

						dealer.checkingRounds(counterPlayerRounds, counterRounds, sizePlayers);

					}
					if (enterButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {

						if (playerAux->getToken() >= dealer.getBigBlind()) {
							file.writeMessage("Enter the game", playerAux->getPositionPlayer(), -1, 'E');
							playerAux->setToken(playerAux->getToken() - dealer.getBigBlind()); //aquiiiii
							playerAux->setIsPlaying(true);
							counterPlayerLeave++;

							node = node->getNext();
							playerAux = node->getPlayer();
							playerAux->setIsBet(false);

							card = playerAux->getCardsInHand(i);
							card1.setTextureCard(card.getImageNumber());
							card = playerAux->getCardsInHand(i + 1);
							card2.setTextureCard(card.getImageNumber());
							card = playerAux->getCardsInHand(i + 2);
							card3.setTextureCard(card.getImageNumber());
							card = playerAux->getCardsInHand(i + 3);
							card4.setTextureCard(card.getImageNumber());

							namePlayerText.setString(playerAux->getNamePlayer());
							token.setString("Token: " + std::to_string(playerAux->getToken()));

							dealer.checkingRounds(counterPlayerRounds, counterRounds, sizePlayers);
						} 
						else {
							needToBet.setString("You don't have enough token!");
							showNeedToBetMessage = true;
						}
					}
				}
			}
		}
	} 
}								