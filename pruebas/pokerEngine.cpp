#include "pokerEngine.h"

//variables globales (todo lo que es grafico)
sf::RenderWindow window(sf::VideoMode(1280, 720), "POKER");
//Las del menu
sf::Texture backgroundMenuFile, backgroundPlayersFile, backgroundGameFile, buttonFile, betButtonFile;
//imagenes para las texturas y mas cosas
sf::Sprite backgroundMenu, backgroundPlayer, backgroundGame, button, betButton;
//Fuentes de texto
sf::Font font1, font2, font3;
//posicion del mouse
sf::Vector2i mousePos;
//evento loop para el juego
sf::Event gameLoop;
//turno y ganador
int turn, winnerPlayer = 0;
//botones
Button playButton, aboutButton, exitButton;
//num of players
int sizePlayers = 0;

//cosas del game();

//cerrar la ventana (refrescar)
void loopRefresh() {

    while (window.pollEvent(gameLoop)) {
        if (gameLoop.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void startMenu() {
    // Load textures and fonts outside the loop
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
                std::cout << "Menu button pressed!" << std::endl;
            }
            else if (aboutButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                aboutWindow();
            }
            else if (exitButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                std::cout << "Exit button pressed!" << std::endl;
                window.close();
            }
        }
    }
}

void aboutWindow() {
	backgroundMenuFile.loadFromFile("Textures/background_black1.png");
	backgroundPlayersFile.loadFromFile("Textures/background_players.png");
	backgroundMenu.setTexture(backgroundMenuFile);
	backgroundGame.setTexture(backgroundGameFile);
	backgroundPlayer.setTexture(backgroundPlayersFile);
	font1.loadFromFile("Fonts/texas_font.otf");

	sf::Text Rules("RULES", font1, 100);
	Rules.setPosition(300, 50);

	Button menuButton, exitButton;

	menuButton.setShapeSize(200, 70);
	menuButton.setFillColorShape(sf::Color::Black);
	menuButton.setText("Menu");
	menuButton.addFillColorText(sf::Color::White);
	menuButton.addFontText(font1);
	menuButton.setShapePosition(980, 490);
	menuButton.setTextPosition(980, 490);

	exitButton.setShapeSize(200, 70);
	exitButton.setFillColorShape(sf::Color::Black);
	exitButton.setText("Exit");
	exitButton.addFillColorText(sf::Color::White);
	exitButton.addFontText(font1);
	exitButton.setShapePosition(980, 610);
	exitButton.setTextPosition(980, 610);

	while (window.isOpen()) {
		loopRefresh();

		window.draw(backgroundMenu);
		window.draw(Rules);
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

	int betAmount = 0;
	int sizeCardsInHand = 4;
	ListPlayer listPlayer(sizePlayers);
	Player* playerAux;
	Dealer dealer;
	Button increaseBetButton, decreaseBetButton, nextButton, leaveButton, enterButton;
	PokerCard card1, card2, card3, card4;
	Node* node = listPlayer.getHead();
	std::string card, cardCommu, player1 = { "Player 1" }, player2{ "Player 2" }, player3{ "Player 3" }, player4{ "Player 4" }, player5{ "Player 5" };
	PokerCard cardComu1, cardComu2, cardComu3, cardComu4, cardComu5;

	font3.loadFromFile("Fonts/limon_font3.otf");
	backgroundGameFile.loadFromFile("Textures/background_game3.png");
	backgroundGame.setTexture(backgroundGameFile);

	card1.setPosition(135, 450);    //TO DO: poner bien las cartas
	card2.setPosition(390, 450);
	card3.setPosition(645, 450);
	card4.setPosition(900, 450);
	playerAux = listPlayer.searchplayer(player1);
	//    int positionInListPLayer = 1;

	 //   if (positionInListPLayer == 1) {
	 //       playerAux = listPlayer.searchplayer("Player 1");
	 //   }
		//if (positionInListPLayer == 2) {
		//	playerAux = listPlayer.searchplayer("Player 2");
		//}
		//if (positionInListPLayer == 3) {
		//	playerAux = listPlayer.searchplayer("Player 3");
		//}
		//if (positionInListPLayer == 4) {
		//	playerAux = listPlayer.searchplayer("Player 4");   //TO DO: get player seria mejor?
		//}
		//if (positionInListPLayer == 5) {
		//	playerAux = listPlayer.searchplayer("Player 5");
		//}
		//if (positionInListPLayer == 6) {
	 //       playerAux = listPlayer.searchplayer("Player 6");
		//}

	//cartas de jugadores XD es para  hacer una division

	dealer.deckShufle();
	playerAux->fillHand(dealer);
	int i = 0;
	card = playerAux->getCardsInHand(i);
	card1.setTextureCard(card);

	card = playerAux->getCardsInHand(i + 1);
	card2.setTextureCard(card);

	card = playerAux->getCardsInHand(i + 2);
	card3.setTextureCard(card);

	card = playerAux->getCardsInHand(i + 3);
	card4.setTextureCard(card);

	card1.setShapeSize(200, 600);
	card2.setShapeSize(200, 600);
	card3.setShapeSize(200, 600);
	card4.setShapeSize(200, 600);

	//cartas cominitarias
	dealer.fillCommunityCards();
	int positionCardCommun = 0;
	cardCommu = dealer.getCommunityCards(positionCardCommun);
	cardComu1.setTextureCard(cardCommu);

	cardCommu = dealer.getCommunityCards(positionCardCommun + 1);
	cardComu2.setTextureCard(cardCommu);

	cardCommu = dealer.getCommunityCards(positionCardCommun + 2);
	cardComu3.setTextureCard(cardCommu);

	cardCommu = dealer.getCommunityCards(positionCardCommun + 3);
	cardComu4.setTextureCard(cardCommu);

	cardCommu = dealer.getCommunityCards(positionCardCommun + 4);
	cardComu5.setTextureCard(cardCommu);

	cardComu1.setShapeSize(140, 190);
	cardComu2.setShapeSize(140, 190);
	cardComu3.setShapeSize(140, 190);
	cardComu4.setShapeSize(140, 190);
	cardComu5.setShapeSize(140, 190);

	cardComu1.setPosition(200, 150);
	cardComu2.setPosition(350, 150);
	cardComu3.setPosition(500, 150);
	cardComu4.setPosition(650, 150);
	cardComu5.setPosition(800, 150);

	decreaseBetButton.setShapeSize(90, 60);
	decreaseBetButton.setFillColorShape(sf::Color::White);
	decreaseBetButton.setText("+10");
	decreaseBetButton.addFillColorText(sf::Color::Black);
	decreaseBetButton.addFontText(font3);
	decreaseBetButton.addLetterSize(35);
	decreaseBetButton.setShapePosition(30, 250);
	decreaseBetButton.setTextPosition(30, 250);

	increaseBetButton.setShapeSize(90, 60);
	increaseBetButton.setFillColorShape(sf::Color::Black);
	increaseBetButton.setText("-10");
	increaseBetButton.addFillColorText(sf::Color::White);
	increaseBetButton.addFontText(font3);
	increaseBetButton.addLetterSize(35);
	increaseBetButton.setShapePosition(30, 350);
	increaseBetButton.setTextPosition(30, 350);

	sf::Text token("Token:", font1, 30);
	token.setFillColor(sf::Color::White);
	token.setPosition(100, 10);

	sf::Text potText("Pot:", font1, 30);
	potText.setFillColor(sf::Color::White);
	potText.setPosition(1180, 10);             // TO DO: colocar en esquina derecha arriba

	sf::Text namePlayerText("Aqui va el nombre", font1, 100);
	namePlayerText.setFillColor(sf::Color::White);
	namePlayerText.setPosition(1100, 10);

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


	while (window.isOpen()) {
		loopRefresh();
		window.draw(backgroundGame);
		card1.drawMe(window);
		card2.drawMe(window);
		card3.drawMe(window);
		card4.drawMe(window);

		cardComu1.drawMe(window);
		cardComu2.drawMe(window);
		cardComu3.drawMe(window);
		cardComu4.drawMe(window);
		cardComu5.drawMe(window);

		nextButton.drawMe(window);
		leaveButton.drawMe(window);
		increaseBetButton.drawMe(window);
		decreaseBetButton.drawMe(window);
		window.draw(token);
		window.draw(potText);
		window.display();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			mousePos = sf::Mouse::getPosition(window);
			if (nextButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {

				playerAux = listPlayer.getPlayerInNextPosition(node);

				// Update UI with the new player's name and token
				namePlayerText.setString(playerAux->getNamePlayer());
				token.setString("Token: " + std::to_string(playerAux->getToken()));

				window.draw(token);           // Draw the updated token
				window.draw(potText);
				window.draw(namePlayerText);  // Draw the updated player name

				window.display();

			}
		}
			if (leaveButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {

				//TO DO: el jugador se sale mientras espera el otro turno

			}
			if (increaseBetButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {

				//playerAux->setTokenBet(playerAuc->getTokenbet() + 10);
				//Aumentar apuesta (hacer que el Pot aumente y ek token del jugador disminuya)
			}
			if (decreaseBetButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {

				playerAux->betManagement(dealer);
				potText.setString("Pot: " + std::to_string(dealer.getPot()));
				token.setString("Token: " + std::to_string(playerAux->getToken()));
				window.draw(potText);  // Aseg�rate de volver a dibujar el texto del pot modificado
				window.draw(token);
				window.display();

				//namePlayerText.setString(std::to_string(pot)); probar

				 /* if(quePlayervaaqui?.getTokenBet() >0){
					playerAux->setTokenBet(quePlayervaaqui->getTokenBet() - 10);
				 }
				quePlayervaaqui?.setTokenBet(+10);
				disminuir apuesta (hacer que el Pot aumente y ek token del jugador disminuya)
				   sf::Text potText;  potText.setString(std::to_string(getPot()));
				*/
			}
		
	}
}

//void handleMouseClick(sf::Event& event, sf::Text& token, sf::Text& potText, sf::Text& namePlayerText) {
//  if (event.type == sf::Event::MouseButtonPressed) {
//		int mouseX = event.mouseButton.x;
//		int mouseY = event.mouseButton.y;
//	if (nextButton.getShape().getGlobalBounds().contains(mouseX, mouseY)) {
//		// L�gica para el bot�n "NEXT"
//		playerAux = listPlayer.getPlayerInNextPosition(node);
//		namePlayerText.setString(playerAux->getNamePlayer());
//		token.setString("Token: " + std::to_string(playerAux->getToken()));
//	}
//	else if (leaveButton.getShape().getGlobalBounds().contains(mouseX, mouseY)) {
//		// L�gica para el bot�n "LEAVE"
//		// ...
//	}
//	else if (increaseBetButton.getShape().getGlobalBounds().contains(mouseX, mouseY)) {
//		// L�gica para el bot�n de aumentar la apuesta
//		// ...
//	}
//	else if (decreaseBetButton.getShape().getGlobalBounds().contains(mouseX, mouseY)) {
//		// L�gica para el bot�n de disminuir la apuesta
//		// ...
//	}
//  }
//}