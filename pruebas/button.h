#pragma once
#include <iostream>
#include <string>
#include "pokerEngine.h"

class Button {

private:
	sf::RectangleShape shape;
	sf::Text text;
	int state;
	
public:
	Button(sf::RectangleShape, int);
	Button();

	void setShapePosition(float, float);
	void setShapeSize(float, float);
	void setFillColorShape(sf::Color);
	sf::Vector2f getSize() const;

	sf::RectangleShape getShape();
	int getState();
	void setState(int);

	std::string getText();
	void setText(std::string);

	void setTextPosition(float, float);
	void addLetterSize(int);
	void addFontText(sf::Font&);  
	void addFillColorText(sf::Color);

	bool isPressed(sf::Vector2f, int);
	void drawMe(sf::RenderWindow&);
};
