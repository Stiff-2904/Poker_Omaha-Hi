#include "player.h"

Player::Player() {
	token = 100;
	currentBet = 0;
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

int Player::getCurrentBet() {
	return this->currentBet;
}

void Player::setCurrentBet(int value ) {
	this->currentBet = value;
}

int Player::getPositionPlayer() {
	return this->positionPlayer;
}

void Player::setPositionPlayer(int positionPlayer) {
	this->positionPlayer = positionPlayer;
}

void Player::increaseCurrentBet(int betValue) {
	if (getToken() >= 10) {
		this->currentBet += betValue;
		setToken(getToken() - betValue);
	}
}

void Player::decreaseCurrentBet(int betValue) {
	if (getCurrentBet() >= 10) {
		this->currentBet -= betValue;
		setToken(getToken() + betValue);
	}
}

void Player::allInCurrentBet(int betValue) {
	if ( betValue <= getToken()) {
		this->currentBet += getToken();
		setToken(0);
	}
}

PokerCard Player::getCardsInHand(int positionVector) {
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
	dealer.setPot(dealer.getPot() + currentBet);
}
