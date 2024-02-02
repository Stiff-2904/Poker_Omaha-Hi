#pragma once

#include "node.h"

class ListPlayer {
private:
	Node* head;
public:
	ListPlayer(int);

	ListPlayer();
	~ListPlayer();

	void pushPlayer(Player*);
	Player* searchplayer(std::string);
	Player* printPlayer(std::string);
};