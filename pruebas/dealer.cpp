#include "dealer.h"

Dealer::Dealer() {
	pot = 0;
}

Dealer::~Dealer() {
}

int Dealer::getPot() { 
	return this->pot;
}

void Dealer::setPot(int pot) {
	this->pot += pot; 
}


std::string Dealer::getCard() {
	for (int i = 0; i < 52; i++) {
		if (!isCardGiven[i]) {
			isCardGiven[i] = true;
			return arrayCards[i];
		}
	}
	return "";
}



void Dealer::deckShufle() {//srind(NULL); en el main se puede

	int iter, randomPos;

	for (iter = 0; iter < 52; iter++) {
		string saveCard = arrayCards[iter];
		randomPos = rand() % (52);
		arrayCards[iter] = arrayCards[randomPos];
		arrayCards[randomPos] = saveCard;
	}
}

void Dealer::fillCommunityCards(){
	for (int i = 0; i < 5; i++) {
		communityCards[i] = getCard();
	}
}

std::string Dealer::getCommunityCards(int position) {
	return communityCards[position];
}

int Dealer::reviewRoyalFlush() {
	return 0;
}
