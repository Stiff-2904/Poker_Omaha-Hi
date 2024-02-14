#pragma once

class Player; 

#include <iostream>
#include <algorithm>
#include "pokerCard.h"
#include "player.h"

const int sizeAllCards = 9;
const int REVIEW_ROYAL_FLUSH_SCORE = 50;
const int STRAIGHT_FLUSH_SCORE = 45;
const int TWO_PAIRS_SCORE = 15;
const int ONE_PAIRS_SCORE = 10;
const int NO_SCORE = -1;

using namespace std;

class Dealer {

private:
	PokerCard arrayCards[52];
	PokerCard communityCards[5];
	int pot;
	int bigBlind = 0;
public:
	Dealer();
	~Dealer();

	int getPot();
	void setPot(int);

	int getBigBlind();
	void setBigBlind(int);

	void fillDeck();
	void deckShufle();

	PokerCard getCard();

	void fillCommunityCards();
	PokerCard getCommunityCards(int);

	void checkingRounds(int&, int&, int);

	PokerCard* bubbleSort(PokerCard*);

	void saveScore(Player*);

	PokerCard* joinCards(Player*);

	int reviewRoyalFlush(Player*);
	int reviewStraightFlush(Player*); 
	int fourOfKind(Player*);
	int fullHouse(Player*);
	int flush(Player*);
	int straight(Player*);
	int threeOfKind(Player*);
	int twoPairs(Player*);
	int onePair(Player*);
	int highCard(Player*);
};
