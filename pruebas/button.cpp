#include "Button.h"

Button::Button() {
	this->state = 0;
}

void Button::setShapePosition(float x, float y) {
	sf::Vector2f position(x, y);
	this->shape.setPosition(position);
}

void Button::setShapeSize(float width, float height) {
	sf::Vector2f size(width, height);
	this->shape.setSize(size);
}

void Button::setFillColorShape(sf::Color color) {  
	this->shape.setFillColor(color);
}

sf::Vector2f Button::getSize() const {
	return shape.getSize();
}

sf::RectangleShape Button::getShape() { return this->shape; }

int Button::getState() { return this->state; }
void Button::setState(int state) { this->state = state; }

std::string Button::getText() { return this->text.getString(); } //clase text en sf

void Button::setText(std::string text) { this->text.setString(text); }

void Button::setTextPosition(float x, float y) {
	const float textPositionX = x + (this->shape.getGlobalBounds().width / 2.f) - (this->text.getGlobalBounds().width / 2.f); //mitad del ancho
	const float textPositionY = y + (this->shape.getGlobalBounds().height / 2.f) - (this->text.getGlobalBounds().height / 2.f); //mitad de altura

	this->text.setPosition(textPositionX, textPositionY);
}


void Button::addLetterSize(int size) { this->text.setCharacterSize(size); }

void Button::addFontText(sf::Font& font) { this->text.setFont(font); }

void Button::addFillColorText(sf::Color color) { this->text.setFillColor(color); }

bool Button::isPressed(sf::Vector2f vec, int state) {   //Vector2f es la posicion de los pixeles digamos 
	if (this->state == 0 && this->shape.getGlobalBounds().contains(vec)) { //para saber el estado y si la figura est  contenida en la figura
		setState(state);
		return true;      //el boton est  siendo presionado 
	}
	return false;
}

void Button::drawMe(sf::RenderWindow& window) {  //externas al main se usa el &
	window.draw(this->shape);
	window.draw(this->text);
}