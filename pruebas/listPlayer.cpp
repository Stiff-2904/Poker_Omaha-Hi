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

Node* ListPlayer::getHead()
{
    return this->head;
}

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

Player* ListPlayer::searchplayer(std::string nameplayer) {// pober getPlayer

    Node* aux = head;
    do {
        if (aux->getPlayer()->getNamePlayer() == nameplayer) {
            return aux->getPlayer();
        }
        aux = aux->getNext();
    } while (aux != head);


    return nullptr;
}

Player* ListPlayer::getPlayerInNextPosition(Node* currentNode) {
    if (currentNode != nullptr && currentNode->getNext() != nullptr) {
        return currentNode->getNext()->getPlayer();
    }
    else {
        return nullptr;
    }
}
