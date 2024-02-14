#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SafeFiles {
public:
	void createRegisterFile();
	int getNextGameNumber();
	void createNewGame();
	void writeMessage(string, int, int, char);
};