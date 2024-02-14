#include "pokerCard.h"

PokerCard::PokerCard() {
	cardNumber = 0;
	suit = "";
	color = "";
	imageName = "";
	isGiven = false;
}

PokerCard::PokerCard(int cardNumber, std::string suit, std::string color) {

	this->cardNumber = cardNumber;
	this->suit = suit;
	this->color = color; 

	this->texture = new sf::Texture();
	this->imageName = "Textures/" + std::to_string(cardNumber) + suit + ".png";
	setTextureCard(imageName);
}

PokerCard::~PokerCard() {
}

int PokerCard::getCardNumber() {
	return this->cardNumber;
}

void PokerCard::setCardNumber(int cardNumber) {
	this->cardNumber = cardNumber;
}

std::string PokerCard::getColor() {
	return this->color;
}

std::string PokerCard::getImageNumber() {
	return this->imageName;
}

std::string PokerCard::getSuit() {	
	return this->suit;
}

void PokerCard::setSuit(std::string suit) {
	this->suit = suit;
}

bool PokerCard::getIsGiven() {
	return this->isGiven;
}

void PokerCard::setIsGiven(bool isGiven) {
	this->isGiven = isGiven;
}

void PokerCard::setShapeSize(float width, float height) {
		sf::Vector2f size(width, height);
		this->shape.setSize(size);
}

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

void PokerCard::setPosition(float x, float y) {
	sf::Vector2f position(x, y);
	this->shape.setPosition(position);
}