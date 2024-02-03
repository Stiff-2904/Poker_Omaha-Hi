#pragma once
#include "dealer.h"
#include <string>

class Player
{
private:
	std::string cardsInHand[4];
	int token;
	int tokenBet;
	std::string namePlayer;
	bool isPlaying;
	//int winnings;
public:
	Player();
	~Player();

	int getToken();
	void setToken(int);

	int getTokenBet();
	void setTokenBet(int);

	std::string getCardsInHand(int);

	//PokerCard* getCardsInHand();

	/*int getWinnings();
	void setWinnings(int);*/

	std::string getNamePlayer();
	void setNamePlayer(int);

	void fillHand(Dealer&);

	void betManagement(Dealer&);
	void printBetManagement(Dealer&);
};

//PokerCards** getCardsInHand() {return cardsInHand; }