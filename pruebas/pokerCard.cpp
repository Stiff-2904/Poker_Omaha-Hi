#include "pokerCard.h"

PokerCard::PokerCard() { this->isGiven = false; }

PokerCard::PokerCard(int numberCard, string color, string suit) {// preguntar si esto es nesesario
	this->numberCard = numberCard;
	this->color = color;
	this->suit = suit;
}

PokerCard::~PokerCard() {
}

int PokerCard::getNumberCard() {
	return this->numberCard;
}

void PokerCard::setNumberCard(int numberCard) {
	this->numberCard = numberCard;
}

string PokerCard::getColor() {
	return this->color;
}

void PokerCard::setColor(string color) {
	this->color = color;
}

string PokerCard::getSuit() {
	return this->suit;
}

void PokerCard::setSuit(string suit) {
	this->suit = suit;
}

bool PokerCard::getIsGiven() {
	return this->isGiven;
}

void PokerCard::setIsGiven(bool isGiven) {
	this->isGiven = isGiven;
}