#include "dealer.h"

Dealer::Dealer() {
	pot = 0;
}

Dealer::~Dealer() {
}

int Dealer::getPot() { return this->pot; }
void Dealer::setPot(int pot) { this->pot = pot; }

PokerCard* Dealer::getCard() {

	for (int i = 0; i < 52; i++) {
		if (!arrayCards[i].getIsGiven()) {
			arrayCards[i].setIsGiven(true);
			return &arrayCards[i];
		}
	}
}

void Dealer::fillDeck() {

	string colors[2] = { "RED", "BLACK" }; //crear los colores en un arreglo para ser asignados a conveniencia en un ciclo
	string suits[4] = { "HEART", "DIAMOND", "SWORD", "CLOVER" };

	int iterSuit, iterNumber, cardCounter = 0;

	for (iterSuit = 0; iterSuit < 4; iterSuit++) {

		for (iterNumber = 1; iterNumber <= 13; iterNumber++) {

			arrayCards[cardCounter].setNumberCard(iterNumber);
			arrayCards[cardCounter].setSuit(suits[iterSuit]);

			if (iterSuit < 2) {

				arrayCards[cardCounter].setColor(colors[0]);

			}
			else {

				arrayCards[cardCounter].setColor(colors[1]);

			}
			cardCounter++;
		}
	}
}


void Dealer::deckShufle() {//srind(NULL); en el main se puede

	int iter, randomPos;

	for (iter = 0; iter < 52; iter++) {
		PokerCard saveCard = arrayCards[iter];
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

PokerCard* Dealer::getCommunityCards(int positionCommunityCards) {
	for (int i = positionCommunityCards; i < 5; i++) { 
		return communityCards[i];
	}
	return nullptr;
}

int Dealer::reviewRoyalFlush() {
	return 0;
}
