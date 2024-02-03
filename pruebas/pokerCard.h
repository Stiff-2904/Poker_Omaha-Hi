#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;

class PokerCard {

private:
	int nameValue;
	sf::RectangleShape shape;
	sf::Texture* texture;
	std::string type;
public:
	PokerCard();
	~PokerCard();

	std::string getType();
	void setType(std::string);

	int getNumberCard();
	void setNumberCard(int);
	void setPosition(sf::Vector2f);

	void setShapeSize(float, float);

	//bool getIsGiven();
	//void setIsGiven(bool);

	sf::RectangleShape getShape();
	void setPosition(float, float);
	void setTextureCard(std::string);
	void drawMe(sf::RenderWindow&);
};
