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
	Player* searchplayer(std::string);
	Player* getPlayerInNextPosition(Node*);
};