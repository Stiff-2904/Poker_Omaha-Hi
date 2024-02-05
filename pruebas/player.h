#pragma once
#include "dealer.h"
#include <string>

class Player {
private:
	std::string cardsInHand[4];
	int token;
	std::string namePlayer = "";
	bool isPlaying = true;
	bool isbet;
public:
	Player();
	~Player();

	int getToken();
	void setToken(int);

	bool getIsPlaying();
	void setIsPlaying(bool);

	bool getIsBet();
	void setIsBet(bool);

	std::string getCardsInHand(int);

	std::string getNamePlayer();
	void setNamePlayer(int);

	void fillHand(Dealer&);

	void betIncrease(Dealer&);
	void betDecrease(Dealer&);
	//void Allin(Dealer&);
};