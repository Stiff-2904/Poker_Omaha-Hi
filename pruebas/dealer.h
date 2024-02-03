#pragma once

#include <iostream>
#include "pokerCard.h"

using namespace std;

class Dealer {

private:
	PokerCard arrayCards[52] = { Pokerheart1.png, heart2.png                  }
	int pot;
	PokerCard* communityCards[5];
public:
	Dealer();
	~Dealer();

	int getPot();
	void setPot(int);

	PokerCard* getCard(); //retorna una carta y se elimina de la baraja / manda el puntero de una carta

	void fillDeck();
	void deckShufle();

	bool checkingToken(int);// revisar si el jugador tiene suficiente plata para seguir jugando

	void fillCommunityCards();
	PokerCard* getCommunityCards(int);

	//funciones de ganar, detectando el masu
	int reviewRoyalFlush();
	int reviewStraightFlush();
};
