#pragma once

class Dealer;

#include <string>
#include "dealer.h"

class Player {

private:
	PokerCard cardsInHand[4];
	int token;
	std::string namePlayer = "";
	bool isPlaying = true;
	bool isbet = false;
	int currentBet;
	int positionPlayer;
	int score;
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

	int getPositionPlayer();
	void setPositionPlayer(int);

	int getScore();
	void setScore(int);

	void increaseCurrentBet(int);
	void decreaseCurrentBet(int);

	PokerCard getCardsInHand(int);

	std::string getNamePlayer();
	void setNamePlayer(int);

	void fillHand(Dealer&);

	void betIncrease(Dealer&);
};