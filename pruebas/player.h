#pragma once
#include "dealer.h"
#include <string>

class Player {
private:
	PokerCard cardsInHand[4];
	int token;
	std::string namePlayer = "";
	bool isPlaying = true;
	bool isbet = false;
	int currentBet;
public:
	Player();
	~Player();

	int getToken();
	void setToken(int);

	bool getIsPlaying();
	void setIsPlaying(bool);

	bool getIsBet();
	void setIsBet(bool);

	int getCurrentBet();
	void setCurrentBet(int);

	void increaseCurrentBet(int);
	void decreaseCurrentBet(int);
	void allInCurrentBet(int);

	PokerCard getCardsInHand(int);

	std::string getNamePlayer();
	void setNamePlayer(int);

	void fillHand(Dealer&);

	void betIncrease(Dealer&);
};