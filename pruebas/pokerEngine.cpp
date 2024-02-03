#include "button.h"
#include "pokerEngine.h"
#include "listPlayer.h"
#include "player.h"

//variables globales (todo lo que es grafico)
sf::RenderWindow window(sf::VideoMode(1280, 720), "POKER");
//Las del menu
sf::Texture backgroundMenuFile, backgroundPlayersFile, backgroundGameFile, buttonFile, betButtonFile;
//imagenes para las texturas y mas cosas
sf::Sprite backgroundMenu, backgroundPlayer, backgroundGame, button, betButton, card;
//Fuentes de texto
sf::Font font1, font2;
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

    // window.setFramerateLimit(24); 

    while (window.isOpen()) {
        loopRefresh();

        window.draw(backgroundMenu);
        window.draw(menuPoker);
        playButton.drawMe(window);
        aboutButton.drawMe(window);
        exitButton.drawMe(window);
        window.display();

        // Event handling to detect button clicks
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
                //agregar una lista circular con 2 players
                sizePlayers = 2;
                game();
            }
			if (button3.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				//agregar una lista circular con 3 players
                sizePlayers = 3;
				game();
			}
			if (button4.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				//agregar una lista circular con 4 players
                sizePlayers = 4;
				game();
			}
			if (button5.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				//agregar una lista circular con 5 players
                sizePlayers = 4;
				game();
			}
			if (button6.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				//agregar una lista circular con 6 players
                sizePlayers = 6;
				game(); 
			}
        }
    }
}

void game() {

    backgroundGameFile.loadFromFile("Textures/background_game3.png");
    backgroundGame.setTexture(backgroundGameFile);
    Button increaseBetButton, decreaseBetButton;
    ListPlayer listOfPlayers(sizePlayers);
    Player* playerAux;
    Dealer dealer;
    PokerCard* cardCommunity;

    playerAux = listOfPlayers.searchplayer("Player 1");        // TEXURE(std:: string)  {this->texture = new...}      for(....) { PokerCard[i].setTexture(cardsInHand[i])}

    dealer.fillDeck();
    dealer.deckShufle();
    playerAux->fillHand(dealer);
    cout << "\n" << playerAux->getNamePlayer();
    dealer.fillCommunityCards();
    for (int i = 0; i < 3; i++) {

        cout << endl;
        cardCommunity = dealer.getCommunityCards(i);
        cout << cardCommunity->getNumberCard() << " " << cardCommunity->getColor() << " " << cardCommunity->getSuit();
    }

    increaseBetButton.setShapeSize(60, 60);
    increaseBetButton.setFillColorShape(sf::Color::Black);
    increaseBetButton.setText("-10");
    increaseBetButton.addFillColorText(sf::Color::White);
    increaseBetButton.addFontText(font2);
    increaseBetButton.addLetterSize(62);
    increaseBetButton.setShapePosition(500, 350);
    increaseBetButton.setTextPosition(500, 305);

    decreaseBetButton.setShapeSize(60, 60);
    decreaseBetButton.setFillColorShape(sf::Color::White);
    decreaseBetButton.setText("+10");
    decreaseBetButton.addFillColorText(sf::Color::Black);
    decreaseBetButton.addFontText(font2);
    decreaseBetButton.addLetterSize(62);
    decreaseBetButton.setShapePosition(400, 400);
    decreaseBetButton.setTextPosition(500, 400);

    sf::Text potText("Pot", font2, 30);
    potText.setFillColor(sf::Color::White);
    potText.setPosition(600, 106);             // TO DO: colocar en esquina derecha arriba

    while (window.isOpen()) {
        loopRefresh();
        window.draw(backgroundGame);
        increaseBetButton.drawMe(window);
        decreaseBetButton.drawMe(window);
        window.draw(potText);
        window.display();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            mousePos = sf::Mouse::getPosition(window);

            if (increaseBetButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {

                //Aumentar apuesta (hacer que el Pot aumente y ek token del jugador disminuya)

            }
            if (increaseBetButton.getShape().getGlobalBounds().contains(mousePos.x, mousePos.y)) {

                //disminuir apuesta (hacer que el Pot aumente y ek token del jugador disminuya)

            }
        }
    }
}