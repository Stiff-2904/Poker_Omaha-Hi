#include "player.h"

Player::Player() {
	token = 100;
}

Player::~Player() { }

int Player::getToken() { 
	return this->token; 
}

void Player::setToken(int token) { 
	this->token = token; 
}

bool Player::getIsPlaying() {
	return this->isPlaying;
}

void Player::setIsPlaying(bool isPlaying) {
	this->isPlaying = isPlaying;
}

bool Player::getIsBet() {
	return this->isbet;
}

void Player::setIsBet(bool isBet) {
	this->isbet = isBet;
}
std::string Player::getCardsInHand(int positionVector) {
	return cardsInHand[positionVector];
}

std::string Player::getNamePlayer() {
	return this->namePlayer;
}

void Player::setNamePlayer(int namePlayer) {
	
    this->namePlayer += "Player " + std::to_string(namePlayer);
}

void Player::fillHand(Dealer& dealer) {

	for (int i = 0; i < 4; i++) {
		cardsInHand[i] = dealer.getCard();
	}
}

void Player::betIncrease(Dealer& dealer) {
	int betAmount = 10;
	if (betAmount <= getToken()) {
		if (getToken() > 0) {
		setToken(getToken() - betAmount);
		dealer.setPot(dealer.getPot() + betAmount);
		}
	}
}

void Player::betDecrease(Dealer& dealer) {
	int betAmount = 10;
	if ( getToken() < 100 && getToken() >= 0) {
		setToken(getToken() + betAmount);
		dealer.setPot(dealer.getPot() - betAmount);
	}
}
