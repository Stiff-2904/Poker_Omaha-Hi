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
	this->pot = pot; 
}


void Dealer::fillDeck() {
	
	string colors[2] = { "red", "black" };
	string suits[4] = { "heart", "diamond", "spades", "clover" };

	int iterSuit, iterNumber, cardCounter = 0;

	for (iterSuit = 0; iterSuit < 4; iterSuit++) {

		for (iterNumber = 1; iterNumber <= 13; iterNumber++) {// 1 a 13 

			if (iterSuit < 2) {
				PokerCard card(iterNumber, suits[iterSuit], colors[0]);
				arrayCards[cardCounter] = card;
			}
			else {
				PokerCard card(iterNumber, suits[iterSuit], colors[1]);
				arrayCards[cardCounter] = card;
			}
			cardCounter++;
		}
	}
}

void Dealer::deckShufle() {

	int iter, randomPos;

	for (iter = 0; iter < 52; iter++) {
		PokerCard saveCard = arrayCards[iter];
		randomPos = rand() % (52);
		arrayCards[iter] = arrayCards[randomPos];
		arrayCards[randomPos] = saveCard;
	}
}

PokerCard Dealer::getCard() {
	int i;
	for (i = 0; i < 52; i++) {
		if (!arrayCards[i].getIsGiven()) {// false // true
			arrayCards[i].setIsGiven(true);
			return arrayCards[i];
		}
	}
}

void Dealer::fillCommunityCards(){
	for (int i = 0; i < 5; i++) {
		communityCards[i] = getCard();
	}
}

PokerCard Dealer::getCommunityCards(int position) {
	return communityCards[position];
}

int Dealer::reviewRoyalFlush() {
	return 0;
}
