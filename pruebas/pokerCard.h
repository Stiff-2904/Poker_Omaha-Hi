#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;

class PokerCard {

private:
	int nameValue;
	bool isGiven;
	sf::RectangleShape shape;
	sf::Texture texture;

public:
	PokerCard();
	PokerCard(int);
	~PokerCard();

	int getNumberCard();
	void setNumberCard(int);

	void setPosition(sf::Vector2f);

	bool getIsGiven();
	void setIsGiven(bool);	

	void setTexture(std::string);
	void draMe(sf::RenderWindow);
};
