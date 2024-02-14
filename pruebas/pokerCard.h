#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;

class PokerCard {

private:
	sf::RectangleShape shape;
	sf::Texture* texture;
	int cardNumber;
	string imageName;
	std::string suit;
	std::string color;
	bool isGiven;
public:
	PokerCard();

	PokerCard(int, std::string, std::string);
	~PokerCard();

	int getCardNumber();
	void setCardNumber(int);

	string getColor();
	void setColor(string);

	std::string getImageNumber();

	std::string getSuit();
	void setSuit(std::string);

	bool getIsGiven();
	void setIsGiven(bool);

	void setPosition(sf::Vector2f);
	void setShapeSize(float, float);

	sf::RectangleShape getShape();
	void setPosition(float, float);

	void setTextureCard(std::string);
	void drawMe(sf::RenderWindow&);
};
