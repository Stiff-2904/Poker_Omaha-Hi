#pragma once

#include <iostream>
#include "pokerCard.h"


class Dealer {
private:
	PokerCard arrayCards[52];
	PokerCard communityCards[5];	
	int pot;
public:
	Dealer();
	~Dealer();

	int getPot();
	void setPot(int);

	void fillDeck();
	void deckShufle();

	PokerCard getCard();

	bool checkingToken(int);// revisar si el jugador tiene suficiente plata para seguir jugando

	void fillCommunityCards();
	PokerCard getCommunityCards(int);

	//funciones de ganar, detectando el masu
	int reviewRoyalFlush();
	int reviewStraightFlush();
};
