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

	void fillAllHandsOfPlayers(Dealer&, int);
};