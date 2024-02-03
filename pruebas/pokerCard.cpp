#include "pokerCard.h"

PokerCard::PokerCard() { this->isGiven = false; }

PokerCard::PokerCard(int numberCard) {
	this->nameValue = numberCard;
}

PokerCard::~PokerCard() {
}

int PokerCard::getNumberCard() {
	return this->nameValue;
}

void PokerCard::setNumberCard(int numberCard) {
	this->nameValue = numberCard;
}

bool PokerCard::getIsGiven() {
	return this->isGiven;
}

void PokerCard::setIsGiven(bool isGiven) {
	this->isGiven = isGiven;
}
void setTexture(std::string typeOfCard) {

//TO DO insertar el metodo que esta en Button CardPoker->shape.setTexture();

}

void drawMe(sf::RenderWindow window) { 
//implementar for
draw.window(this->shape);

}

// hacer el metodo que toquen la carta HMMMMMMMMMM

//hacen las figuras y cargan las imagenes ahi 
//shape texture le enviamos el vect
//texure recibe la carta 