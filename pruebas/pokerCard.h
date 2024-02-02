#pragma once
#include <iostream>

using namespace std;

class PokerCard {

private:
	int numberCard;
	string color;
	string suit; //palo
	bool isGiven;
public:
	PokerCard();
	PokerCard(int, string, string);
	~PokerCard();

	int getNumberCard();
	void setNumberCard(int);

	string getColor();
	void setColor(string);

	string getSuit();
	void setSuit(string);

	bool getIsGiven();
	void setIsGiven(bool);
};
