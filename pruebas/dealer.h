#pragma once

#include <iostream>
#include "pokerCard.h"


class Dealer {

private:
	std::string arrayCards[52] = {  "Textures/1heart.png", "Textures/2heart.png", "Textures/3heart.png", "Textures/4heart.png", "TexturesTextures/5heart.png",
		                            "Textures/6heart.png", "Textures/7heart.png", "Textures/8heart.png", "Textures/9heart.png", "Textures/10heart.png",
		                            "Textures/11heart.png", "Textures/12heart.png", "Textures/13heart.png",
							     	"Textures/1diamond.png", "Textures/2diamond.png", "Textures/3diamond.png", "Textures/4diamond.png", "Textures/5diamond.png",
								    "Textures/6diamond.png", "Textures/7diamond.png", "Textures/8diamond.png", "Textures/9diamond.png", "Textures/10diamond.png",
									"Textures/11diamond.png", "Textures/12diamond.png", "Textures/13diamond.png",
									"Textures/1clover.png", "Textures/2clover.png", "Textures/3clover.png", "Textures/4clover.png", "Textures/5clover.png",
									"Textures/6clover.png", "Textures/7clover.png", "Textures/8clover.png", "Textures/9clover.png", "Textures/10clover.png",
									"Textures/11clover.png", "Textures/12clover.png", "Textures/13clover.png",
									"Textures/1spades.png", "Textures/2spades.png", "Textures/3spades.png", "Textures/4spades.png", "Textures/5spades.png",
									"Textures/6spades.png", "Textures/7spades.png", "Textures/8spades.png", "Textures/9spades.png", "Textures/10spades.png",
									"Textures/11spades.png", "Textures/12spades.png", "Textures/13spades.png",
	};
	bool isCardGiven[52] = { false };
	int pot;
	std::string communityCards[5];
public:
	Dealer();
	~Dealer();

	int getPot();
	void setPot(int);

	bool getIsGiven();
	void setIsGiven(bool);

	std::string getCard(); //retorna una carta y se elimina de la baraja / manda el puntero de una carta

	void deckShufle();

	bool checkingToken(int);// revisar si el jugador tiene suficiente plata para seguir jugando

	void fillCommunityCards();
	PokerCard* getCommunityCards(int);





	//funciones de ganar, detectando el masu
	int reviewRoyalFlush();
	int reviewStraightFlush();
};
