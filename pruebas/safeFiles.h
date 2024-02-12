#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createRegisterFile();
int getNextGameNumber();
void createNewGame();
void writeMessage(string, int, int, char);
void gameOptions(int);
void startNewGame(int);