#include "pokerCard.h"

PokerCard::PokerCard() {
	this->texture = new sf::Texture();
}

PokerCard::~PokerCard() {
}

std::string PokerCard::getType() {
	return this->type;
}

void PokerCard::setType(std::string type) {
	this->type = type;
}

int PokerCard::getNumberCard() {
	return this->nameValue;
}

void PokerCard::setNumberCard(int numberCard) {
	this->nameValue = numberCard;
}

void PokerCard::setShapeSize(float width, float height) {
		sf::Vector2f size(width, height);
		this->shape.setSize(size);
}

//bool PokerCard::getIsGiven() {
//	return this->isGiven;
//}

sf::RectangleShape PokerCard::getShape() {
	return this->shape;
}

void PokerCard::setTextureCard(std::string nameTexture) {

	if (texture->loadFromFile(nameTexture)) {
		shape.setTexture(texture);
	}
}

void PokerCard::drawMe(sf::RenderWindow &window) {
	window.draw(shape);
}

//TO DO insertar el metodo que esta en Button CardPoker->shape.setTexture();

void PokerCard::setPosition(float x, float y) {
	sf::Vector2f position(x, y);
	this->shape.setPosition(position);
}





// hacer el metodo que toquen la carta HMMMMMMMMMM

//hacen las figuras y cargan las imagenes ahi 
//shape texture le enviamos el vect
//texure recibe la carta 