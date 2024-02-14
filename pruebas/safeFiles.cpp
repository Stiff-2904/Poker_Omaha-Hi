#include "safeFiles.h";

const string FOLDER_NAME = "gameFile";
const string FILE_NAME = "PokerGame.txt";

void SafeFiles::createRegisterFile() {
    ofstream file(FOLDER_NAME + "/" + FILE_NAME);
    if (file.is_open()) {
        file << ">Game1--------------------------" << endl;
        file.close();
    }
    else {
        cerr << "Error: Could not create the file." << endl;
    }
}

int SafeFiles::getNextGameNumber() {
    ifstream file(FOLDER_NAME + "/" + FILE_NAME);
    string line;
    int gameNumber = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find(">Game") != string::npos) {
                int number = stoi(line.substr(5));
                if (number > gameNumber) {
                    gameNumber = number;
                }
            }
        }
        file.close();
    }
    else {
        cerr << "Error: Could not open the file." << endl;
    }

    return gameNumber + 1;
}

void SafeFiles::createNewGame() {
    int nextGameNumber = getNextGameNumber();
    ofstream file(FOLDER_NAME + "/" + FILE_NAME, ios::app);
    if (file.is_open()) {
        file << "\n>Game" << nextGameNumber << "--------------------------" << endl;
        file.close();
    }
    else {
        cerr << "Error: Could not open the file." << endl;
    }
}

void SafeFiles::writeMessage(string message, int playerNumber, int betNumber, char messageType) {
    ofstream file(FOLDER_NAME + "/" + FILE_NAME, ios::app);
    if (file.is_open()) {
        if (messageType == 'R') {
            file << message << endl;
        }
        else if (messageType == 'P') {
            file << playerNumber << " " << message << endl;
        }
        else if (messageType == 'T' || messageType == 'E' || messageType == 'O' || messageType == 'W') {
            file << "Player" << playerNumber << " " << message << endl;
        }
        else if (messageType == 'B') {
            file << "Player" << playerNumber << " " << message << " " << betNumber << " bets" << endl;
        }
        file.close();
    }
    else {
        cerr << "Error: Could not open the file." << endl;
    }
}