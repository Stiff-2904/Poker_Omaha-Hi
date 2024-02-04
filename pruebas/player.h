#pragma once
#include "dealer.h"
#include <string>

class Player
{
private:
	std::string cardsInHand[4];
	int token;
	std::string namePlayer;
	bool isPlaying;
	//int winnings;
public:
	Player();
	~Player();

	int getToken();
	void setToken(int);

	bool getIsPlaying();
	void setIsPlaying(bool);

	std::string getCardsInHand(int);

	std::string getNamePlayer();
	void setNamePlayer(int);

	void fillHand(Dealer&);

	void betManagement(Dealer&);
};

//PokerCards** getCardsInHand() {return cardsInHand; }