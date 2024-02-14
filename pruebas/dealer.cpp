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

		for (iterNumber = 1; iterNumber <= 13; iterNumber++) {

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
	int iter;
	for (iter = 0; iter < 52; iter++) {
		if (!arrayCards[iter].getIsGiven()) {
			arrayCards[iter].setIsGiven(true);
			return arrayCards[iter];
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

void Dealer::saveScore(Player* player) {
	int score = 0;
	if ((reviewStraightFlush(player)) != -1) {
		score = reviewStraightFlush(player);
		player->setScore(score);
	}else if ((twoPairs(player)) != -1) {
		score = twoPairs(player);
		player->setScore(score);
	}else if ((onePair(player)) != -1) {
		score = onePair(player);
		player->setScore(score);
	}else if ((highCard(player)) != -1) {
		score = highCard(player);
		player->setScore(score);
	}
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
	const std::string suits[4] = { "heart", "diamond", "spades", "clover" };
	const int royalFlushValues[5] = { 1, 10, 11, 12, 13 };

	bool hasRoyalFlush = true;

	std::string suitOfFirstCard = player->getCardsInHand(0).getSuit();
	for (int i = 1; i < 4; ++i) {
		if (player->getCardsInHand(i).getSuit() != suitOfFirstCard) {
			hasRoyalFlush = false;
			break;
		}
	}

	for (int i = 0; i < 5; ++i) {
		if (player->getCardsInHand(i).getCardNumber() != royalFlushValues[i]) {
			hasRoyalFlush = false;
			break;
		}
	}
	return hasRoyalFlush ? REVIEW_ROYAL_FLUSH_SCORE : NO_SCORE;
}

int Dealer::reviewStraightFlush(Player* player) {
	PokerCard* allCards = joinCards(player);
	allCards = bubbleSort(allCards);

	bool checkStraightFlush = false;
	int consecutiveCount = 1;

	for (int i = 0; i < sizeAllCards - 1; i++) {
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
	return checkStraightFlush ? STRAIGHT_FLUSH_SCORE : NO_SCORE;
}

int Dealer::twoPairs(Player* player) {

	PokerCard* allCards = joinCards(player); 
	bool foundFirstPair = false, foundSecondPair = false;
	int firstPairValue = 0, secondPairValue = 0;

	allCards = bubbleSort(allCards);

	for (int i = 0; i < sizeAllCards - 1; i++) {
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
	return (foundFirstPair && foundSecondPair) ? TWO_PAIRS_SCORE : -1;
}

int Dealer::onePair(Player* player) {

	PokerCard* allCards = joinCards(player);

	bool isOnePair = false;
	int j, i;

	for (i = 0; i < sizeAllCards - 1; i++) {
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
	return isOnePair ? ONE_PAIRS_SCORE : NO_SCORE;
}

int Dealer::highCard(Player* player) {
	int highestCard = 0, cardNumber;

	for (int j = 0; j < 4; j++) {
		cardNumber = player->getCardsInHand(j).getCardNumber();
		highestCard = std::max(highestCard, cardNumber);
	}
	return highestCard;
}