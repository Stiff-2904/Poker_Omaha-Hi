#include "player.h"

Player::Player() {
	token = 200;
	tokenBet = 40;
}

Player::~Player() { }


int Player::getToken() { return this->token; }
void Player::setToken(int token) { this->token = token; }

int Player::getTokenBet() { return this->tokenBet; }
void Player::setTokenBet(int token) { this->tokenBet = tokenBet; }

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
	int TokenToBet = getTokenBet();
	if (getTokenBet() >= dealer.getPot()) {
		setToken(getToken() - TokenToBet);
		dealer.setPot(TokenToBet + dealer.getPot());
		setTokenBet(100);
	}
}