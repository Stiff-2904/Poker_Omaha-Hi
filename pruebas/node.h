#pragma once
#include "player.h"

class Node {
private:
    Player* player;
    Node* next;
public:
    Node(Player*);
    ~Node();

    void setPlayer(Player*);
    Player* getPlayer();
    void setNext(Node*);
    Node* getNext();
};