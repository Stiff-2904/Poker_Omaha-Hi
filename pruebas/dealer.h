#pragma once

class Player; 
class Node;

#include <iostream>
#include <algorithm>
#include "pokerCard.h"
#include "node.h"
#include "player.h"

const int sizeAllCards = 9;
using namespace std;

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

	bool checkingToken(int);// revisar si el jugador tiene suficiente plata para seguir jugando???

	void fillCommunityCards();
	PokerCard getCommunityCards(int);

	void checkingRounds(int&, int&, int);

	PokerCard* bubbleSort(PokerCard*);

	Player* checkingWinner(Player*, Node* ,int);

	PokerCard* joinCards(Player*);

	int reviewRoyalFlush(Player*); // va a valer 50 puntos osea retorna 50 si hay ganador sino -1
	int reviewStraightFlush(Player*); // va a valer 45 puntos osea retorna 45 si hay ganador sino - 1
	int fourOfKind(Player*); // va a valer 40 puntos osea retorna 40 si hay ganador sino - 1
	int fullHouse(Player*); // va a valer 35 puntos osea retorna 35 si hay ganador sino - 1
	int flush(Player*); // va a valer 30 puntos osea retorna 30 si hay ganador sino - 1
	int straight(Player*); // va a valer 25 puntos osea retorna 25 si hay ganador sino - 1
	int threeOfKind(Player*); // va a valer 20 puntos osea retorna 20 si hay ganador sino - 1
	int twoPairs(Player*); // va a valer 15 puntos osea retorna 15 si hay ganador sino - 1
	int onePair(Player*); // va a valer 10 puntos osea retorna 10 si hay ganador sino - 1
	int highCard(Player*); // este retorna la carta mas alta solo se usa en casos de que los demas no hayan sido positivos
};
