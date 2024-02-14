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
		if (!arrayCards[i].getIsGiven()) {
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

PokerCard* Dealer::bubbleSort(PokerCard* vectorCards) {
	int i, j;
	PokerCard aux;

	for (i = 0; i < sizeAllCards - 1; i++) {
		for (j = 0; j < sizeAllCards - i - 1; j++) {
			if (vectorCards[j].getCardNumber() > vectorCards[j + 1].getCardNumber()) {
				aux = vectorCards[j];
				vectorCards[j] = vectorCards[j + 1];
				vectorCards[j + 1] = aux;
			}
		}
	}
	return vectorCards;
}

Player* Dealer::checkingWinner(Player* player, Node* node, int sizePlayers) {
	Player* winner = nullptr;
	int maxScore = -1, score;

	for (int i = 0; i < sizePlayers; i++) {
		score = -1;
		if ((score = reviewRoyalFlush(player)) != -1) {
			if (score > maxScore) {
				maxScore = score;
				winner = player;
			}
		}
		if ((score = reviewStraightFlush(player)) != -1) {
			if (score > maxScore) {
				maxScore = score;
				winner = player;
			}
		}
		// Agregar otras funciones de evaluación aquí...
		if ((score = twoPairs(player)) != -1) {
			if (score > maxScore) {
				maxScore = score;
				winner = player;
			}
		}
		if ((score = onePair(player)) != -1) {
			if (score > maxScore) {
				maxScore = score;
				winner = player;
			}
		}
		if ((score = highCard(player)) != -1) {
			if (score > maxScore) {
				maxScore = score;
				winner = player;
			}
		}
		node = node->getNext();
		player = node->getPlayer();
	}
	return winner;
}

PokerCard* Dealer::joinCards(Player* player) {

	PokerCard* allCards = new PokerCard[sizeAllCards];

	for (int i = 0; i < 5; i++) {
		allCards[i] = communityCards[i];
	}

	for (int i = 0; i < 4; i++) {
		allCards[i + 5] = player->getCardsInHand(i);
	}

	return allCards;
}

int Dealer::reviewRoyalFlush(Player* player) {
	std::string suits[4] = { "heart", "diamond", "spades", "clover" };
	int cardNumbers[5] = { 1, 10, 11, 12, 13 };
	bool found = false;

	PokerCard* allCards = joinCards(player);
	allCards = bubbleSort(allCards);
	bool hasRoyalFlush = true;

	for (int i = 0; i < sizeAllCards; ++i) {
		//aqui
	}

	delete[] allCards;

	return hasRoyalFlush ? 50 : -1;
}


int Dealer::reviewStraightFlush(Player* player) {

	PokerCard* allCards = joinCards(player);
	allCards = bubbleSort(allCards);

	bool checkStraightFlush = false;
	int consecutiveCount = 1;

	for (int i = 0; i < sizeAllCards; i++) {
		if (allCards[i].getSuit() == allCards[i + 1].getSuit() &&
			allCards[i].getCardNumber() == allCards[i + 1].getCardNumber() - 1) {
			consecutiveCount++;
			if (consecutiveCount >= 5) {
				checkStraightFlush = true;
				break;
			}
		}
		else {
			consecutiveCount = 1;
		}
	}

	delete[] allCards;

	return checkStraightFlush ? 45 : -1;
}

int Dealer::twoPairs(Player* player) {

	PokerCard* allCards = joinCards(player); 
	bool foundFirstPair = false, foundSecondPair = false;
	int firstPairValue = 0, secondPairValue = 0;

	allCards = bubbleSort(allCards);

	for (int i = 0; i < sizeAllCards; i++) {
		if (allCards[i].getCardNumber() == allCards[i + 1].getCardNumber()) {
			if (!foundFirstPair) {
				foundFirstPair = true;
				firstPairValue = allCards[i].getCardNumber();
			}
			else if (allCards[i].getCardNumber() != firstPairValue) {
				foundSecondPair = true;
				secondPairValue = allCards[i].getCardNumber();
				break;
			}
		}
	}

	delete[] allCards;

	return (foundFirstPair && foundSecondPair) ? 15 : -1;
}

int Dealer::onePair(Player* player) {

	PokerCard* allCards = joinCards(player);

	bool isOnePair = false;
	int j, i;

	for (i = 0; i < sizeAllCards; i++) {
		for (j = i + 1; j < sizeAllCards; j++) {
			if (allCards[i].getCardNumber() == allCards[j].getCardNumber()) {
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

//

int Dealer::highCard(Player* player) {// esto evalua cada jugador toms en checkingRounds habria que hacer un for hasta sizePlayer
	int highestCard = 0, cardNumber;

	for (int j = 0; j < 4; j++) {
		cardNumber = player->getCardsInHand(j).getCardNumber();
		highestCard = std::max(highestCard, cardNumber);
	}

	return highestCard;
}