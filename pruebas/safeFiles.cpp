#include "safeFiles.h";

const string folderName = "gameFile";
const string fileName = "PokerGame.txt";

void SafeFiles::createRegisterFile() {
    ofstream file(folderName + "/" + fileName);
    if (file.is_open()) {
        file << ">Game1--------------------------" << endl;
        file.close();
    }
    else {
        cerr << "Error: Could not create the file." << endl;
    }
}

int SafeFiles::getNextGameNumber() {
    ifstream file(folderName + "/" + fileName);
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
    ofstream file(folderName + "/" + fileName, ios::app);
    if (file.is_open()) {
        file << "\n>Game" << nextGameNumber << "--------------------------" << endl;
        file.close();
    }
    else {
        cerr << "Error: Could not open the file." << endl;
    }
}

void SafeFiles::writeMessage(string message, int playerNumber, int chipsNumber, char messageType) {
    // tipo de mensaje: 
    // 'T' = Registrar turno, 'B' = Registrar apuesta, 'I' = Registrar nuevo jugador integrado, 'O' = Registrar retirada de jugador, 'W' = Registrar ganador,
   //'R' = Ronda de registro iniciada, 'P' = Jugadores de registro en la mesa.

    ofstream file(folderName + "/" + fileName, ios::app);
    if (file.is_open()) {
        if (messageType == 'R') {
            file << message << endl;
        }
        else if (messageType == 'P') {
            file << playerNumber << " " << message << endl;
        }
        else if (messageType == 'T' || messageType == 'I' || messageType == 'O' || messageType == 'W') {
            file << "Player" << playerNumber << " " << message << endl;
        }
        else if (messageType == 'B') {
            file << "Player" << playerNumber << " " << message << " " << chipsNumber << " bets" << endl;
        }
        file.close();
    }
    else {
        cerr << "Error: Could not open the file." << endl;
    }
}