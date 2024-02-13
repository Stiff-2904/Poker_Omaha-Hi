#include "dealer.h"

Dealer::Dealer() {
	pot = 0;
	bigBlind = 0;
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

int Dealer::getBigBlind() {
	return this->bigBlind;
}

void Dealer::setBigBlind(int bigBlind) {
	this->bigBlind = bigBlind;
}

void Dealer::fillCommunityCards(){
	for (int i = 0; i < 5; i++) {
		communityCards[i] = getCard();
	}
}

PokerCard Dealer::getCommunityCards(int position) {
	return communityCards[position];
}

void Dealer::checkingRounds(int& counterPlayerRounds, int& counterRounds, int sizePlayers) {

	if (counterPlayerRounds < sizePlayers) {
		counterPlayerRounds++;
	}
	else {
		counterPlayerRounds = 1;
		counterRounds++;
	}
}

Player* Dealer::checkingWinner(Player* player, int sizePlayers) {

	return player;
}

int* Dealer::joinCards(int* allCards, Player* player) {
	int sizeAllCards = 9;

	for (int i = 0; i < 5; i++) {
		allCards[i] = communityCards[i].getCardNumber();
	}

	for (int i = 0; i < 4; i++) {
		allCards[i + 5] = player->getCardsInHand(i).getCardNumber();
	}
	return allCards;
}


int Dealer::reviewRoyalFlush(Player* player) {// revisarsssss
	std::string suits[4] = { "heart", "diamond", "spades", "clover" };
	int cardNumbers[5] = { 1, 10, 11, 12, 13 }; // As, 10, J, Q, K 
	bool hasRoyalFlush = true, found = false;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 4; ++j) {
			if ((player->getCardsInHand(i).getSuit() == suits[j] &&
				player->getCardsInHand(i).getCardNumber() == cardNumbers[i]) ||
				(communityCards[i].getSuit() == suits[j] &&
					communityCards[i].getCardNumber() == cardNumbers[i])) {
				found = true;
				break;
			}
		}
		if (!found) {
			hasRoyalFlush = false;
			break;
		}
	}

	return hasRoyalFlush ? 50 : -1;
}


int Dealer::onePair(Player* player) {
	int* allCards = new int[9];
	allCards = joinCards(allCards, player);
	bool isOnePair = false;

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (allCards[i] == allCards[j]) {
				isOnePair = true;
				break;
			}
		}
		if (isOnePair) {
			break;
		}
	}

	delete[] allCards;

	return isOnePair ? 10 : -1;
}


int Dealer::highCard(Player* player) {// esto evalua cada jugador toms en checkingRounds habria que hacer un for hasta sizePlayer
	int highestCard = 0, cardNumber;

	for (int j = 0; j < 4; j++) {
		cardNumber = player->getCardsInHand(j).getCardNumber();
		highestCard = std::max(highestCard, cardNumber);
	}

	return highestCard;
}