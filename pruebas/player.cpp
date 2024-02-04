#include "player.h"

Player::Player() {
	token = 200;
}

Player::~Player() { }


int Player::getToken() { return this->token; }
void Player::setToken(int token) { this->token = token; }

bool Player::getIsPlaying() {
	return this->isPlaying;
}

void Player::setIsPlaying(bool isPlaying) {
	this->isPlaying = isPlaying;
}

std::string Player::getCardsInHand(int positionVector) {
	return cardsInHand[positionVector];
}

//PokerCard* getCardsInHand() {
//	return;
//}

//int Player::getWinnings() {	return this->winnings; }
//void Player::setWinnings(int winnings) { this->winnings = winnings; }

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

void Player::betManagement(Dealer& dealer) {
	int betAmount = 10;
	if (betAmount <= getToken()) {
		setToken(getToken() - betAmount);
		dealer.setPot(betAmount);
	}
}
