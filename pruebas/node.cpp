#include "node.h"

Node::Node(Player* player) {
	this->player = player;
	next = nullptr;
}

Node::~Node() {
	delete player;
	delete next;
}

void Node::setPlayer(Player* player) {
	this->player = player;
}

Player* Node::getPlayer() {
	return player;
}

void Node::setNext(Node* next) {
	this->next = next;
}

Node* Node::getNext() {
	return next;
}