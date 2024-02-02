#pragma once

#include <iostream>
#include "pokerCard.h"

using namespace std;

class Dealer {

private:
	PokerCard arrayCards[52];// delete[0] arrayCards;
	int pot;
public:
	Dealer();
	~Dealer();

	int getPot();
	void setPot(int);

	PokerCard getCardHand(); //retorna una carta y se elimina de la baraja / manda el puntero de una carta

	void fillDeck();
	void deckShufle();

	bool checkingToken(int);// revisar si el jugador tiene suficiente plata para seguir jugando


	//funciones de ganar, detectando el masu
	int reviewRoyalFlush();
	int reviewStraightFlush();
};
