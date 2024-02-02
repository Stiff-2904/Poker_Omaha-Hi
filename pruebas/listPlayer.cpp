#include "ListPlayer.h"

ListPlayer::ListPlayer(int sizeOfPlayers) { 
    head = nullptr; 
    for (int i = 0; i < sizeOfPlayers; i++) {
        Player* player = new Player();
        player->setNamePlayer(i + 1);
        pushPlayer(player);
    }
}

ListPlayer::ListPlayer(){}

ListPlayer::~ListPlayer() {}

void ListPlayer::pushPlayer(Player* player) {
    Node* newNode = new Node(player);

    if (head == nullptr) {
        head = newNode;
        head->setNext(newNode);
    }
    else {
        Node* aux = head;

        while (aux->getNext() != head) {
            aux = aux->getNext();
        }
        aux->setNext(newNode);
        newNode->setNext(head);
    }
}

Player* ListPlayer::searchplayer(std::string nameplayer) {

    Node* aux = head;
    do {
        if (aux->getPlayer()->getNamePlayer() == nameplayer) {
            return aux->getPlayer();
        }
        aux = aux->getNext();
    } while (aux != head);


    return nullptr;
}