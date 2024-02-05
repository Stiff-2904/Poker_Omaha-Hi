#pragma once

#include "node.h"

class ListPlayer {
private:
	Node* head;
public:
	ListPlayer(int);

	ListPlayer();
	~ListPlayer();

	Node* getHead();

	void pushPlayer(Player*);
	Player* searchplayer(std::string);// no se esta usando

	void fillAllHandsOfPlayers(Dealer&, int);
};