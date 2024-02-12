#include "safeFiles.h";

const string folderName = "gameFile";
const string fileName = "AllGames.txt";

void createRegisterFile() {
    ofstream file(folderName + "/" + fileName);
    if (file.is_open()) {
        file << ">Game1--------------------------" << endl;
        file.close();
    }
    else {
        cerr << "Error: Could not create the file." << endl;
    }
}

int getNextGameNumber() {
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

void createNewGame() {
    int nextGameNumber = getNextGameNumber();
    ofstream file(folderName + "/" + fileName, ios::app);
    if (file.is_open()) {
        file << "\n>Game" << nextGameNumber << "--------------------------" << endl;
        file.close();
        cout << "Added game " << nextGameNumber << " to the file." << endl;
    }
    else {
        cerr << "Error: Could not open the file." << endl;
    }
}

void writeMessage(string message, int playerNumber, int chipsNumber, char messageType) {
    // messageType: 'T' = Record turn, 'A' = Record bet, 'I' = Record new integrated player, 'R' = Record player retreat, 'G' = Record winner,
    //'C' = Record round started, 'M' = Record players on the table.

    ofstream file(folderName + "/" + fileName, ios::app);
    if (file.is_open()) {
        if (messageType == 'C') {
            file << message << endl;
        }
        else if (messageType == 'M') {
            file << playerNumber << " " << message << endl;
        }
        else if (messageType == 'T' || messageType == 'I' || messageType == 'R' || messageType == 'G') {
            file << "Player" << playerNumber << " " << message << endl;
        }
        else if (messageType == 'A') {
            file << "Player" << playerNumber << " " << message << " " << chipsNumber << " chips" << endl;
        }
        file.close();
    }
    else {
        cerr << "Error: Could not open the file." << endl;
    }
}

void gameOptions(int sizePlayers) {
    writeMessage("Round started\n", -1, -1, 'C');
    writeMessage("Players on the table\n", sizePlayers, -1, 'M');
    int currentPlayerTurn = 1;
    int opt = 0;

    while (true) {
        system("cls");
        writeMessage("has the turn", currentPlayerTurn, -1, 'T');

        cout << "POKER-----------------------------" << endl;
        cout << "1. Bet chips" << endl;
        cout << "2. Integrate player" << endl;
        cout << "3. Retreat from the game" << endl;
        cout << "4. Exit" << endl;
        cout << "-> ";
        cin >> opt;

        if (opt == 1) {
            int chips;
            cout << endl << "Chips to bet: ";
            cin >> chips;
            writeMessage("bet", currentPlayerTurn, chips, 'A');
            currentPlayerTurn++;
        }
        else if (opt == 2) {
            int player;
            cout << endl << "Player to integrate: ";
            cin >> player;
            writeMessage("integrated into the game", player, -1, 'I');
            currentPlayerTurn = player;
        }
        else if (opt == 3) {
            writeMessage("retreated from the game", currentPlayerTurn, -1, 'R');
            currentPlayerTurn++;
        }
        else if (opt == 4) {
            writeMessage("won the game", currentPlayerTurn, -1, 'G');
            break;
        }
    }
}

void startNewGame(int sizePlayers) {

    if (sizePlayers < 1 || sizePlayers > 6) {
        cerr << "Error: The number of players must be between 1 and 6." << endl;
        return;
    }

    ifstream checkFile(folderName + "/" + fileName);
    if (!checkFile) {
        createRegisterFile();
        cout << "Created the file AllGames.txt with the first game." << endl;
    }
    else {
        checkFile.close();
        createNewGame();
    }

    gameOptions(sizePlayers);
}
