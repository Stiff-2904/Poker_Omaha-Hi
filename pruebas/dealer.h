#pragma once

#include <iostream>
#include "pokerCard.h"


class Dealer {
private:
	PokerCard arrayCards[52];
	PokerCard communityCards[5];	
	int pot;
	int bigBlind;
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

	bool checkingToken(int);// revisar si el jugador tiene suficiente plata para seguir jugando

	void fillCommunityCards();
	PokerCard getCommunityCards(int);

	//esta llama a toda el resto para que revice las manos de los jugadores y de el ganador retornandolo


	//funciones de ganar, detectando el masu
	int reviewRoyalFlush(Dealer);
	int reviewStraightFlush(Dealer);
};
