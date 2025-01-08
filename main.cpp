#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

char gerak, playInGame;
string attack, defaultColor = "\033[0m", lightRed = "\033[091m", lightBlue = "\033[094m", lightGreen = "\033[092m", lightBlack = "\033[090m";
int attackAI, destroyerShipLength = 2, submarineShipLength = 3, cruiserShipLength = 3, battleshipShipLength = 4, carrierShipLength = 5;
int destroyerY = 1, destroyerX = 1, submarineY = 1, submarineX = 1, cruiserY = 1, cruiserX = 1, battleshipY = 1, battleshipX = 1, carrierX = 1, carrierY = 1;
int destroyer = 2, submarine = 3, cruiser = 4, battleship = 5, carrier = 6;
bool isHrDestroyer = true, isHrSubmarine = true, isHrCruiser = true, isHrBattleship = true, isHrCarrier = true;
bool play, done;
int selectedOpt;
bool canBePlaced;

int mapBattleShip[9][11] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int mapBattleShip2[9][11] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int mapBattleShipAi[9][11] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void displayMenu(int selectedOption, int menuChoice, int &pick){
    system("cls");
    int theSize;
    vector<string> mainMenu = {"Play Game", "Leaderboard", "History", "\033[91mExit\033[0m"};
    vector<string> gamemodeMenu = {"VS AI", "2 Player", "Back"};
    vector<string> difficultyMenu = {"\033[32mBeginner\033[0m mode", "\033[33mIntermediate\033[0m mode", "\033[35mAdvanced\033[0m mode", "\033[31mGacor !!!\033[0m", "Back"};
    vector<string> shipMenu = {"\033[31m**\033[0m Destroyer", "\033[32m***\033[0m Submarine", "\033[33m***\033[0m Cruiser", "\033[34m****\033[0m Battleship", "\033[35m*****\033[0m Carrier", "Continue", "Back"};
//    vector<string>
    while (true){
        system("cls");
        if (menuChoice == 1){
            theSize = mainMenu.size();
            cout << "== Welcome to \033[091mBATTLE\033[094mSHIP\033[0m ==" << endl;
            for (int i = 0; i < mainMenu.size(); i++){
                if (i == selectedOption)
                    cout << "> " << mainMenu[i] << endl;
                else
                    cout << "  " << mainMenu[i] << endl;
            }
        } else if (menuChoice == 2){
            theSize = gamemodeMenu.size();
            cout << lightBlack << "== Welcome to BATTLESHIP ==" << defaultColor << endl;
            cout << "  Play Game "<< lightGreen << "(Selected)" << defaultColor << endl;
            for (int i = 0; i < gamemodeMenu.size(); i++){
                if (i == selectedOption)
                    cout << "  > " << gamemodeMenu[i] << endl;
                else
                    cout << "    " << gamemodeMenu[i] << endl;
            }
            cout << lightBlack << "  Leaderboard" << endl;
            cout << "  History" << endl;
            cout << "  Exit" << defaultColor << endl;
        } else if (menuChoice == 3){
            theSize = difficultyMenu.size();
            cout << "== \033[091mBATTLE\033[094mSHIP\033[0m Artificial Intelligence ==" << endl;
            cout << "Choose the difficulty of your AI:" << endl;
            for (int i = 0; i < difficultyMenu.size(); i++){
                if (i == selectedOption)
                    cout << "> " << difficultyMenu[i] << endl;
                else
                    cout << "  " << difficultyMenu[i] << endl;
            }
        } else if (menuChoice > 3 && menuChoice < 10){
            theSize = shipMenu.size();

            string difficultyPick;
            string playerPick;
            if (menuChoice == 4) difficultyPick = "\033[92mBeginner\033[0m";
            if (menuChoice == 5) difficultyPick = "\033[93mIntermediate\033[0m";
            if (menuChoice == 6) difficultyPick = "\033[95mAdvanced\033[0m";
            if (menuChoice == 7) difficultyPick = "\033[091mGacor !!!\033[0m";
            if (menuChoice == 8) playerPick = "\033[094mPlayer 1\033[0m";
            if (menuChoice == 9) playerPick = "\033[091mPlayer 2\033[0m";

            if (menuChoice < 8){
                cout << "== You have selected " << difficultyPick << " Difficulty ==" << endl;
                cout << "Please set up the position of your ship :" << endl;
            } else if (menuChoice < 10){
                cout << "== \033[091mBATTLE\033[094mSHIP\033[0m PlayerVSPlayer ==" << endl;
                cout << "Please " << playerPick << " set up the position of your ship :" << endl;
            }
            for (int i = 0; i < shipMenu.size(); i++){
                if (i == selectedOption)
                    cout << "> " << shipMenu[i] << endl;
                else
                    cout << "  " << shipMenu[i] << endl;
            }
        }
        char key = getch();
        if (key == 'w' || key == 'W') {
            selectedOption = (selectedOption - 1 + theSize) % theSize;
        }
        else if (key == 's' || key == 'S') {
            selectedOption = (selectedOption + 1) % theSize;
        }
        else if (key == '\r') {
            system("cls");
            pick = selectedOption + 1;
            break;
        }
    }
}

void displayBoard(int mapBattleShip[9][11]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 11; j++){
            if(mapBattleShip[i][j] == 1){
                cout << lightBlack << "# " << defaultColor;
            } else if(mapBattleShip[i][j] == 2){
                cout << "\033[31m*\033[0m ";
            } else if(mapBattleShip[i][j] == 3){
                cout << "\033[32m*\033[0m ";
            } else if(mapBattleShip[i][j] == 4){
                cout << "\033[33m*\033[0m ";
            } else if(mapBattleShip[i][j] == 5){
                cout << "\033[34m*\033[0m ";
            } else if(mapBattleShip[i][j] == 6){
                cout << "\033[35m*\033[0m ";
            } else {
                cout << char(250) << " ";
            }
        }
        cout << endl;
    }
}

void displayBoardPlay(int mapBattleShip[9][11], string color, bool &cheat, int num1, int num2){
    int shipInMap[5] = {0, 0, 0, 0, 0};

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 11; j++){
            if(mapBattleShip[i][j] == 7){
                shipInMap[0]++;
            } else if (mapBattleShip[i][j] == 8){
                shipInMap[1]++;
            } else if (mapBattleShip[i][j] == 9){
                shipInMap[2]++;
            } else if (mapBattleShip[i][j] == 10){
                shipInMap[3]++;
            } else if (mapBattleShip[i][j] == 11){
                shipInMap[4]++;
            }
        }
    }

    if (!cheat){
        cout << color;
        for(int i = 0; i < 9; i++) {
            if (i == 0 || i == 8) {
                for (int j = 0; j < 11; j++) {
                    if(j == 0 || j == 10){
                        cout << "    ";
                    } else {
                        if (i == num1){
                            char letter = 'a' + j - 1;
                            cout << " " << letter << " ";
                        }
                    }
                }
            } else {
                for (int j = 0; j < 11; j++) {
                    if (mapBattleShip[i][j] == 1 && j == num2) {
                        cout << "   ";
                    } else if (mapBattleShip[i][j] == 1){
                        cout << "  " << i << " ";
                    } else if (mapBattleShip[i][j] == 7 && shipInMap[0] == 2){
                        cout << "[\033[31m*\033[0m" << color << "]";
                    } else if (mapBattleShip[i][j] == 8 && shipInMap[1] == 3){
                        cout << "[\033[32m*\033[0m" << color << "]";
                    } else if (mapBattleShip[i][j] == 9 && shipInMap[2] == 3){
                        cout << "[\033[33m*\033[0m" << color << "]";
                    } else if (mapBattleShip[i][j] == 10 && shipInMap[3] == 4){
                        cout << "[\033[34m*\033[0m" << color << "]";
                    } else if (mapBattleShip[i][j] == 11 && shipInMap[4] == 5){
                        cout << "[\033[35m*\033[0m" << color << "]";
                    } else if (mapBattleShip[i][j] == 7){
                        cout << "[O]";
                    } else if (mapBattleShip[i][j] == 8){
                        cout << "[O]";
                    } else if (mapBattleShip[i][j] == 9){
                        cout << "[O]";
                    } else if (mapBattleShip[i][j] == 10){
                        cout << "[O]";
                    } else if (mapBattleShip[i][j] == 11){
                        cout << "[O]";
                    } else if (mapBattleShip[i][j] == 12){
                        cout << "[X]";
                    } else {
                        cout << "[ ]";
                    }
                }
            }
            cout << endl;
        }
        cout << defaultColor;
    } else {
        cout << color;
        for(int i = 0; i < 9; i++) {
            if (i == 0 || i == 8) {
                for (int j = 0; j < 11; j++) {
                    if(j == 0 || j == 10){
                        cout << "    ";
                    } else {
                        if (i == num1){
                            char letter = 'a' + j - 1;
                            cout << " " << letter << " ";
                        }
                    }
                }
            } else {
                for (int j = 0; j < 11; j++) {
                    if (mapBattleShip[i][j] == 1 && j == num2){
                        cout << "   ";
                    } else if (mapBattleShip[i][j] == 1) {
                        cout << "  " << i << " ";
                    } else {
                        if(mapBattleShip[i][j] == 2){
                            cout << "[\033[31m*\033[0m" << color << "]";
                        } else if(mapBattleShip[i][j] == 3){
                            cout << "[\033[32m*\033[0m" << color << "]";
                        } else if(mapBattleShip[i][j] == 4){
                            cout << "[\033[33m*\033[0m" << color << "]";
                        } else if(mapBattleShip[i][j] == 5){
                            cout << "[\033[34m*\033[0m" << color << "]";
                        } else if(mapBattleShip[i][j] == 6){
                            cout << "[\033[35m*\033[0m" << color << "]";
                        } else if (mapBattleShip[i][j] == 7){
                            cout << "[O]";
                        } else if (mapBattleShip[i][j] == 8){
                            cout << "[O]";
                        } else if (mapBattleShip[i][j] == 9){
                            cout << "[O]";
                        } else if (mapBattleShip[i][j] == 10){
                            cout << "[O]";
                        } else if (mapBattleShip[i][j] == 11){
                            cout << "[O]";
                        } else if (mapBattleShip[i][j] == 12){
                            cout << "[X]";
                        } else {
                            cout << "[ ]";
                        }
                    }
                }
            }
            cout << endl;
        }
        cout << defaultColor;
    }
}

void gerakKapal(char gerak, int &x, int &y, int &shipLength, int modelsShip, bool &isHorizontal, int mapBatShip[9][11]) {
    for (int i = 0; i < shipLength; i++) {
        if (isHorizontal) {
            mapBatShip[y][x + i] = 0;
        } else {
            mapBatShip[y + i][x] = 0;
        }
    }

    if (gerak == 'w') {
        bool canMove = true;
        for (int i = 0; i < shipLength; i++) {
            if (isHorizontal) {
                if (mapBatShip[y - 1][x + i] != 0) {
                    canMove = false;
                    break;
                }
            } else {
                if (mapBatShip[y - 1][x] != 0) {
                    canMove = false;
                    break;
                }
            }
        }
        if (canMove) {
            y--;
        }
    } else if (gerak == 'a') {
        bool canMove = true;
        for (int i = 0; i < shipLength; i++) {
            if (isHorizontal) {
                if (mapBatShip[y][x - 1] != 0) {
                    canMove = false;
                    break;
                }
            } else {
                if (mapBatShip[y + i][x - 1] != 0) {
                    canMove = false;
                    break;
                }
            }
        }
        if (canMove) {
            x--;
        }
    } else if (gerak == 's') {
        bool canMove = true;
        for (int i = 0; i < shipLength; i++) {
            if (isHorizontal) {
                if (mapBatShip[y + 1][x + i] != 0) {
                    canMove = false;
                    break;
                }
            } else {
                if (mapBatShip[y + shipLength][x] != 0) {
                    canMove = false;
                    break;
                }
            }
        }
        if (canMove) {
            y++;
        }
    } else if (gerak == 'd') {
        bool canMove = true;
        for (int i = 0; i < shipLength; i++) {
            if (isHorizontal) {
                if (mapBatShip[y][x + shipLength] != 0) {
                    canMove = false;
                    break;
                }
            } else {
                if (mapBatShip[y + i][x + 1] != 0) {
                    canMove = false;
                    break;
                }
            }
        }
        if (canMove) {
            x++;
        }
    } else if (gerak == 'r') {
        bool canRotate = true;

        if (isHorizontal) {
            for (int i = 0; i < shipLength; i++) {
                if (y + i >= 11 || mapBatShip[y + i][x] != 0) {
                    canRotate = false;
                    break;
                }
            }
        } else {
            for (int i = 0; i < shipLength; i++) {
                if (x + i >= 9 || mapBatShip[y][x + i] != 0) {
                    canRotate = false;
                    break;
                }
            }
        }

        if (canRotate) {
            for (int i = 0; i < shipLength; i++)
                mapBatShip[y][x + i] = 0;
            isHorizontal = !isHorizontal;
        }
    }

    for (int i = 0; i < shipLength; i++) {
        if (isHorizontal) {
            mapBatShip[y][x + i] = modelsShip;
        } else {
            mapBatShip[y + i][x] = modelsShip;
        }
    }
}

void spawnShip(int shipLength, int &x, int &y, int modelsShip, bool &isHorizontal, int mapBatShip[9][11]){
    for(int i = 0; i < shipLength; i++){
        if (isHorizontal){
            mapBatShip[y][x + i] = modelsShip;
        } else {
            mapBatShip[y + i][x] = modelsShip;
        }
    }
}

bool availableSpot(int shipLength, int &x, int &y, int modelsShip, bool &isHorizontal, int mapBatShip[9][11]){
    for (int i = 0; i < shipLength; i++){
        if (isHorizontal){
            if (mapBatShip[y][x + i] != 0 && mapBatShip[y][x + i] != modelsShip)
                return false;
        } else {
            if (mapBatShip[y + i][x] != 0 && mapBatShip[y + i][x] != modelsShip)
                return false;
        }
    }
    return true;
}



void deployShip(string name, char colorCode, int shipLength, int mapBatShip[9][11]){
    cout << "== " << name << " Ship \033[3" << colorCode << "m";
    for (int i = 0; i < shipLength; i++){
        cout << "*";
    }
    cout << "\033[0m ==" << endl << endl;
    displayBoard(mapBatShip);
    cout << endl;
    cout << "Press w/a/s/d to move your ship" << endl;
    cout << "Press enter to save the position of ship" << endl;
    cout << "Press r to rotate your ship" << endl;
    cout << "Press c to randomize" << endl;
}

void placeOneShipRandomly(int &x, int &y, int shipLength, int modelShip, int mapBatShip[9][11], string name, bool &isHr){
    bool canDeploy = false;
    int randomX;
    int randomY;
    int randomRotate;

    while (!canDeploy){
        canDeploy = true;
        randomX = 1 + rand() % 9;
        randomY = 1 + rand() % 7;
        randomRotate = rand() % 2;

//        cout << "Rotate: " << randomRotate << ", Coordinates: " << randomX << " and " << randomY << " of " << name << endl;
//        Sleep(200);

        for (int i = 0; i < shipLength; i++){
            if (randomRotate == 1){
                isHr = false;
            }
            if (isHr){
                if (randomX + i >= 10 || mapBatShip[randomY][randomX + i] != 0){
                    canDeploy = false;
//                    cout << "Failed attempt" << " of " << name << endl;
//                    Sleep(200);
                    break;
                }
            } else {
                if (randomY + i >= 8 || mapBatShip[randomY + i][randomX] != 0){
                    canDeploy = false;
//                    cout << "Failed attempt" << " of " << name << endl;
//                    Sleep(200);
                    break;
                }
            }
        }
        if (canDeploy){
//            cout << "Placing ship" << " of " << name << endl;
//            Sleep(200);
            x = randomX;
            y = randomY;
            for (int i = 0; i < shipLength; i++){
                if (isHr)
                    mapBatShip[y][x + i] = modelShip;
                else
                    mapBatShip[y + i][x] = modelShip;
            }
        }
    }
}

void placeAllShipsRandomly(int mapBatShip[9][11]){
    srand(time(0));

    for (int i = 1; i < 8; i++){
        for (int j = 1; j < 10; j++){
            if (mapBatShip[i][j] == 2 || mapBatShip[i][j] == 3 || mapBatShip[i][j] == 4 || mapBatShip[i][j] == 5 || mapBatShip[i][j] == 6)
                mapBatShip[i][j] = 0;
        }
    }
    isHrDestroyer = true; isHrSubmarine = true; isHrCruiser = true; isHrBattleship = true; isHrCarrier = true;

    placeOneShipRandomly(destroyerX, destroyerY, destroyerShipLength, destroyer, mapBatShip, "Destroyer", isHrDestroyer);
    placeOneShipRandomly(submarineX, submarineY, submarineShipLength, submarine, mapBatShip, "Submarine", isHrSubmarine);
    placeOneShipRandomly(cruiserX, cruiserY, cruiserShipLength, cruiser, mapBatShip, "Cruiser", isHrCruiser);
    placeOneShipRandomly(battleshipX, battleshipY, battleshipShipLength, battleship, mapBatShip, "Battleship", isHrBattleship);
    placeOneShipRandomly(carrierX, carrierY, carrierShipLength, carrier, mapBatShip, "Carrier", isHrCarrier);
//    system("pause");
}

void deployAndOperateShip(char gerak, char colorCode, int shipLength, int &x, int &y, int modelShip, bool &isHorizontal, bool &done, int mapBatShip[9][11], string name){
    spawnShip(shipLength, x, y, modelShip, isHorizontal, mapBatShip);
    deployShip(name, colorCode, shipLength, mapBatShip);
    gerak = getch();
    gerakKapal(gerak, x, y, shipLength, modelShip, isHorizontal, mapBatShip);

    if (gerak == '\r'){
        done = true;
    } else if (gerak == 'c'){
        placeAllShipsRandomly(mapBatShip);
    }
    system("cls");
}

void risetCoordinate(bool &isHr, int &x, int &y){
    isHr = true;
    x = 1;
    y = 1;
}

void risetMap(int mapBattleShip[9][11]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 11; j++){
            if(mapBattleShip[i][j] != 1 && mapBattleShip[i][j] != 0){
                mapBattleShip[i][j] = 0;
            }
        }
    }
}

void resetMapAndShips(int mapBatShip[9][11]){
    risetCoordinate(isHrDestroyer, destroyerX, destroyerY);
    risetCoordinate(isHrSubmarine, submarineX, submarineY);
    risetCoordinate(isHrCruiser, cruiserX, cruiserY);
    risetCoordinate(isHrBattleship, battleshipX, battleshipY);
    risetCoordinate(isHrCarrier, carrierX, carrierY);
    risetMap(mapBatShip);

}

bool validateCoordinateInput(string coordinates){
    if (coordinates.size() > 2 || coordinates.size() < 2)
        return false;
    else {
        if (coordinates.at(0) < 96 || coordinates.at(0) > 105)
            return false;
        else if (coordinates.at(1) < 49 || coordinates.at(1) > 55)
            return false;
    }
    return true;
}

int processCoordinates(string coordinates){
    int num1 = coordinates.at(0) - 96; // a jadi 1, b jadi 2, dsb
    int num2 = coordinates.at(1) - 48;
    int decipher = num1 * 10 + num2;

    return decipher;
}

void displayShipPlay(int mapBattleShip[9][11]){
    int shipLengthInMap[5] = {0, 0, 0, 0, 0};
    int shipLength[5] = {2, 3, 3, 4, 5};
    string shipColors[5] = {"\033[31m*\033[0m", "\033[32m*\033[0m", "\033[33m*\033[0m", "\033[34m*\033[0m", "\033[35m*\033[0m"};
    string destroyerDisplay, submarineDisplay, cruiserDisplay, battleshipDisplay, carrierDisplay;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 11; j++){
            if(mapBattleShip[i][j] == 2){
                shipLengthInMap[0]++;
            } else if (mapBattleShip[i][j] == 3){
                shipLengthInMap[1]++;
            } else if (mapBattleShip[i][j] == 4){
                shipLengthInMap[2]++;
            } else if (mapBattleShip[i][j] == 5){
                shipLengthInMap[3]++;
            } else if (mapBattleShip[i][j] == 6){
                shipLengthInMap[4]++;
            }
        }
    }

    if(shipLengthInMap[0] != 0){
        for(int i = 0; i < shipLength[0]; i++){
            destroyerDisplay += shipColors[0];
        }
    } else {
        for(int i = 0; i < shipLengthInMap[0]; i++){
            destroyerDisplay += shipColors[0];
        }
    }

    if(shipLengthInMap[1] != 0){
        for(int i = 0; i < shipLength[1]; i++){
            submarineDisplay += shipColors[1];
        }
    } else {
        for(int i = 0; i < shipLengthInMap[1]; i++){
            submarineDisplay += shipColors[1];
        }
    }

    if(shipLengthInMap[2] != 0){
        for(int i = 0; i < shipLength[2]; i++){
            cruiserDisplay += shipColors[2];
        }
    } else {
        for(int i = 0; i < shipLengthInMap[2]; i++){
            cruiserDisplay += shipColors[2];
        }
    }

    if(shipLengthInMap[3] != 0){
        for(int i = 0; i < shipLength[3]; i++){
            battleshipDisplay += shipColors[3];
        }
    } else {
        for(int i = 0; i < shipLengthInMap[3]; i++){
            battleshipDisplay += shipColors[3];
        }
    }

    if(shipLengthInMap[4] != 0){
        for(int i = 0; i < shipLength[4]; i++){
            carrierDisplay += shipColors[4];
        }
    } else {
        for(int i = 0; i < shipLengthInMap[4]; i++){
            carrierDisplay += shipColors[4];
        }
    }

    cout << setw(5) << " " << destroyerDisplay << " " << submarineDisplay << "  " << cruiserDisplay << "  " << battleshipDisplay << " " << carrierDisplay;
    cout << endl;
}

string attackForAI(int mapBattleShip[9][11], int ctrShip, int ctrSend, string difficulty){
    int ctr = 0;
    int cy_ship[17];
    int cx_ship[17];
    int cy_guess[63];
    int cx_guess[63];
    int y, x;
    char yChar;
    string result;
    bool isSame;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 11; j++){
            if(mapBattleShip[i][j] == 2 || mapBattleShip[i][j] == 3 || mapBattleShip[i][j] == 4 || mapBattleShip[i][j] == 5 || mapBattleShip[i][j] == 6){
                cx_ship[ctr] = i;
                cy_ship[ctr] = j;
                ctr++;
            }
        }
    }

    if (difficulty == "Easy"){
        if(ctrSend % 6 == 0){
            y = cy_ship[ctrShip];
            x = cx_ship[ctrShip];

            cy_guess[ctrSend] = y;
            cx_guess[ctrSend] = x;
        } else {
            do {
                x = rand () % 7 + 1;
                y = rand () % 9 + 1;

                isSame = true;
                for(int i = 0; i < ctrSend; i++){
                    if(cy_guess[i] != y && cx_guess[i] != x){
                        isSame = false;
                        break;
                    }
                }
            } while (isSame);

            cy_guess[ctrSend] = y;
            cx_guess[ctrSend] = x;
        }
    } else if (difficulty == "Medium"){
        if(ctrSend % 4 == 0){
            y = cy_ship[ctrShip];
            x = cx_ship[ctrShip];

            cy_guess[ctrSend] = y;
            cx_guess[ctrSend] = x;
        } else {
            do {
                x = rand () % 7 + 1;
                y = rand () % 9 + 1;

                isSame = true;
                for(int i = 0; i < ctrSend; i++){
                    if(cy_guess[i] != y && cx_guess[i] != x){
                        isSame = false;
                        break;
                    }
                }
            } while (isSame);

            cy_guess[ctrSend] = y;
            cx_guess[ctrSend] = x;
        }
    } else if (difficulty == "Hard"){
        if(ctrSend % 2 == 0){
            y = cy_ship[ctrShip];
            x = cx_ship[ctrShip];

            cy_guess[ctrSend] = y;
            cx_guess[ctrSend] = x;
        } else {
            do {
                x = rand () % 7 + 1;
                y = rand () % 9 + 1;

                isSame = true;
                for(int i = 0; i < ctrSend; i++){
                    if(cy_guess[i] != y && cx_guess[i] != x){
                        isSame = false;
                        break;
                    }
                }
            } while (isSame);

            cy_guess[ctrSend] = y;
            cx_guess[ctrSend] = x;
        }
    } else if (difficulty == "Gacor"){
        y = cy_ship[ctrShip];
        x = cx_ship[ctrShip];
    }

    yChar = 'a' + y - 1;
    result = string(1, yChar) + to_string(x);

    return result;
}

void positioningShips(int mapBattleShip[9][11], bool &play, int selectShip){
    switch(selectShip){
        case 1:{
            do {
                if (availableSpot(destroyerShipLength, destroyerX, destroyerY, destroyer, isHrDestroyer, mapBattleShip))
                    deployAndOperateShip(gerak, '1', destroyerShipLength, destroyerX, destroyerY, destroyer, isHrDestroyer, done, mapBattleShip, "Destroyer");
                else {
                    cout << "\033[031mDestroyer\033[0m cannot be deployed!\nPlease move the current ship at the spawnpoint";
                    Sleep(1000);
                    break;
                }
            } while (!done);
            selectedOpt = 0;
        break;
        }
        case 2:{
            do {
                if (availableSpot(submarineShipLength, submarineX, submarineY, submarine, isHrSubmarine, mapBattleShip))
                    deployAndOperateShip(gerak, '2', submarineShipLength, submarineX, submarineY, submarine, isHrSubmarine, done, mapBattleShip, "Submarine");
                else {
                    cout << "\033[032mSubmarine\033[0m cannot be deployed!\nPlease move the current ship at the spawnpoint";
                    Sleep(1000);
                    break;
                }
            } while (!done);
            selectedOpt = 1;
        break;
        }
        case 3:{
            do {
                if (availableSpot(cruiserShipLength, cruiserX, cruiserY, cruiser, isHrCruiser, mapBattleShip))
                    deployAndOperateShip(gerak, '3', cruiserShipLength, cruiserX, cruiserY, cruiser, isHrCruiser, done, mapBattleShip, "Cruiser");
                else {
                    cout << "\033[033mCruiser\033[0m cannot be deployed!\nPlease move the current ship at the spawnpoint";
                    Sleep(1000);
                    break;
                }
            } while (!done);
            selectedOpt = 2;
        break;
        }
        case 4:{
            do {
                if (availableSpot(battleshipShipLength, battleshipX, battleshipY, battleship, isHrBattleship, mapBattleShip))
                    deployAndOperateShip(gerak, '4', battleshipShipLength, battleshipX, battleshipY, battleship, isHrBattleship, done, mapBattleShip, "Battle");
                else {
                    cout << "\033[034mBattleship\033[0m cannot be deployed!\nPlease move the current ship at the spawnpoint";
                    Sleep(1000);
                    break;
                }
            } while (!done);
            selectedOpt = 3;
        break;
        }
        case 5:{
            do {
                if (availableSpot(carrierShipLength, carrierX, carrierY, carrier, isHrCarrier, mapBattleShip))
                    deployAndOperateShip(gerak, '5', carrierShipLength, carrierX, carrierY, carrier, isHrCarrier, done, mapBattleShip, "Carrier");
                else {
                    cout << "\033[035mCarrier\033[0m cannot be deployed!\nPlease move the current ship at the spawnpoint";
                    Sleep(1000);
                    break;
                }
            } while (!done);
            selectedOpt = 4;
        break;
        }
        case 6:{
        int ctr = 0;

            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 11; j++){
                    if(mapBattleShip[i][j] == 0){
                        ctr++;
                    }
                }
            }

            if (ctr == 46){
                play = true;
            } else {
                cout << "Please set up all the positions of your ships" << endl;
                Sleep(1000);
                system("cls");
                selectedOpt = 5;
            }
            break;
        }
    }
}

void attackPhase(int mapBattleShipOne[9][11], int mapBattleShipTwo[9][11], int &ctr, int &aiShip, int &plyrOnePoint, int &plyrTwoPoint, string attack1, string attack2 ,string AIorVS){
    if(ctr % 2 == 0){
        int y = processCoordinates(attack1) % 10;
        int x = processCoordinates(attack1) / 10 % 10;

        if(mapBattleShipOne[y][x] == 0 || mapBattleShipOne[y][x] == 1){
            mapBattleShipOne[y][x] = 12;
            cout << "No ship was hit!";
        } else if (mapBattleShipOne[y][x] >= 2 && mapBattleShipOne[y][x] <= 6){
            if(mapBattleShipOne[y][x] == 2){
                mapBattleShipOne[y][x] = 7;
            } else if (mapBattleShipOne[y][x] == 3){
                mapBattleShipOne[y][x] = 8;
            } else if (mapBattleShipOne[y][x] == 4){
                mapBattleShipOne[y][x] = 9;
            } else if (mapBattleShipOne[y][x] == 5){
                mapBattleShipOne[y][x] = 10;
            } else if (mapBattleShipOne[y][x] == 6){
                mapBattleShipOne[y][x] = 11;
            }
            ctr--;
            plyrTwoPoint++;
            if (AIorVS == "AI")
                aiShip--;

            cout << 17 - plyrTwoPoint << " more points to go!";
        } else {

            ctr--;
            cout << "Invalid coordinates!";
        }
        Sleep(500);
    } else {
       int y = processCoordinates(attack2) % 10;
       int x = processCoordinates(attack2) / 10 % 10;

       if(mapBattleShipTwo[y][x] == 0 || mapBattleShipTwo[y][x] == 1){
            mapBattleShipTwo[y][x] = 12;
            cout << "No ship was hit!";
        } else if (mapBattleShipTwo[y][x] >= 2 && mapBattleShipTwo[y][x] <= 6){
            if(mapBattleShipTwo[y][x] == 2){
                mapBattleShipTwo[y][x] = 7;
            } else if (mapBattleShipTwo[y][x] == 3){
                mapBattleShipTwo[y][x] = 8;
            } else if (mapBattleShipTwo[y][x] == 4){
                mapBattleShipTwo[y][x] = 9;
            } else if (mapBattleShipTwo[y][x] == 5){
                mapBattleShipTwo[y][x] = 10;
            } else if (mapBattleShipTwo[y][x] == 6){
                mapBattleShipTwo[y][x] = 11;
            }
            ctr--;
            plyrOnePoint++;
            cout << 17 - plyrOnePoint << " more points to go!";
        } else {
            ctr--;
            cout << "Invalid coordinates!";
        }
        Sleep(500);
    }
}


int main()
{
    int menu, menuPlayGame, levelGame, selectShip;

    int textMenu[16][29] = {
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 2},
        {2, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 2},
        {2, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 2},
        {2, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 2},
        {2, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 3, 0, 3, 0, 3, 3, 3, 0, 3, 3, 3, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 3, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 3, 3, 3, 0, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 3, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 3, 0, 3, 0, 3, 3, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
    };

    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 29; j++){
            if (textMenu[i][j] == 1){
                cout << lightRed << "* " << defaultColor;
                Sleep(5);
            } else if (textMenu[i][j] == 2){
                cout << lightBlack << "# " << defaultColor;
            } else if (textMenu[i][j] == 3){
                cout << lightBlue << "* " << defaultColor;
                Sleep(5);
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    Sleep(1500);
    do {
        selectedOpt = 0;
        displayMenu(selectedOpt, 1, menu);

        switch(menu){
            case 1:{
                selectedOpt = 0;
                do {
                    displayMenu(selectedOpt, 2, menuPlayGame);

                    switch(menuPlayGame){
                        case 1:{
                            selectedOpt = 0;
                            do {
                                play = false;
                                displayMenu(selectedOpt, 3, levelGame);

                                    switch(levelGame){
                                        case 1:{
                                            resetMapAndShips(mapBattleShip);
                                            resetMapAndShips(mapBattleShipAi);
                                            selectedOpt = 0;
                                            do {
                                                displayMenu(selectedOpt, 4, selectShip);

                                                done = false;
                                                positioningShips(mapBattleShip, play, selectShip);
                                            } while (selectShip != 7 && !play);
                                            selectedOpt = 0;
                                            system("cls");

                                            if (play){
                                                placeAllShipsRandomly(mapBattleShipAi);
                                                bool revealShipsCheat = false;
                                                int ctr = 0;
                                                int ctrWin1 = 0;
                                                int ctrAI = 0;
                                                int ctrShip = 16;
                                                int ctrSend = 0;
                                                string attackAI;

                                                do {
                                                    cout << " ======   AI " << lightRed << "BATTLE" << lightBlue << "SHIP" << defaultColor << "   ======\n" << endl;
                                                    if (ctr % 2 == 0){
                                                        displayBoardPlay(mapBattleShipAi, lightRed, revealShipsCheat, 0, 10);
                                                        displayShipPlay(mapBattleShipAi);
                                                        cout << endl;
                                                        cout << lightRed << setw(16) << "" << "AI" << defaultColor << endl;
                                                        cout << endl;
                                                        cout << "--------  \033[92mBEGINNER MODE\033[0m  --------\n" << endl;
                                                        cout << lightBlue << setw(14) << "" << "PLAYER" << defaultColor << endl;
                                                        cout << endl;
                                                        displayShipPlay(mapBattleShip);
                                                        displayBoardPlay(mapBattleShip, lightBlue, revealShipsCheat, 8, 10);
                                                        cout << endl;
                                                    } else {
                                                        displayBoardPlay(mapBattleShipAi, lightRed, revealShipsCheat, 0, 10);
                                                        displayShipPlay(mapBattleShipAi);
                                                        cout << lightRed << setw(16) << "" << "AI" << defaultColor << endl;
                                                        cout << endl;
                                                        cout << "--------  \033[92mBEGINNER MODE\033[0m  --------\n" << endl;
                                                        cout << lightBlue << setw(14) << "" << "PLAYER" << defaultColor << endl;
                                                        cout << endl;
                                                        displayShipPlay(mapBattleShip);
                                                        displayBoardPlay(mapBattleShip, lightBlue, revealShipsCheat, 8, 10);
                                                        cout << endl;
                                                    }

                                                    if (ctr % 2 == 0){
                                                        ctr++;
                                                        cout << lightBlue << "Player 1" << defaultColor << "'s turn!\nEnter your attack coordinates (ex." << lightRed << " b6, f2" << defaultColor << "): " << lightRed;
                                                        cin >> attack;
                                                        cout << defaultColor;
                                                    } else {
                                                        ctr++;
                                                        attackAI = attackForAI(mapBattleShip, ctrShip, ctrSend, "Easy");
                                                        cout << lightRed << "AI" << defaultColor << "'s turn!\nEntering attack coordinates: " << lightBlue;
                                                        cout << attackAI << endl;
                                                        cout << defaultColor;
                                                        ctrSend++;
                                                        Sleep(1000);
                                                    }
                                                    if (attack == "777"){
                                                        ctr--;
                                                        if (!revealShipsCheat){
                                                            cout << "Cheat activated";
                                                        } else {
                                                            cout << "Cheat deactivated";
                                                        }
                                                        Sleep(500);
                                                        revealShipsCheat = !revealShipsCheat;
                                                    } else if (attack == "x"){
                                                        cout << "Exiting Program";
                                                        for (int i = 0; i < 3; i++){
                                                            cout << ". ";
                                                            Sleep(200);
                                                        }
                                                    } else {
                                                        if (!validateCoordinateInput(attack)){
                                                            ctr--;
                                                            cout << "Invalid Input!";
                                                            Sleep(500);
                                                        } else {
                                                            attackPhase(mapBattleShip, mapBattleShipAi, ctr, ctrShip, ctrWin1, ctrAI, attackAI, attack, "AI");
                                                        }
                                                    }
                                                    system("cls");
                                                } while (attack != "x" && ctrWin1 != 17 && ctrAI != 17);
                                                if(ctrWin1 == 17){
                                                    cout << lightBlue << "You " << defaultColor << "Win !!!";
                                                    Sleep(3000);
                                                    system("cls");
                                                    break;
                                                } else if (ctrAI == 17){
                                                    cout << lightRed << "AI " << defaultColor << "Win !!!";
                                                    Sleep(3000);
                                                    system("cls");
                                                    break;
                                                }
                                            }
                                        break;
                                        }
                                        case 2:{
                                            resetMapAndShips(mapBattleShip);
                                            resetMapAndShips(mapBattleShipAi);
                                            selectedOpt = 0;

                                            do {
                                                displayMenu(selectedOpt, 5, selectShip);

                                                done = false;
                                                positioningShips(mapBattleShip, play, selectShip);
                                            } while (selectShip != 7 && !play);
                                            selectedOpt = 1;
                                            system("cls");

                                            if (play){
                                                placeAllShipsRandomly(mapBattleShipAi);
                                                bool revealShipsCheat = false;
                                                int ctr = 0;
                                                int ctrWin1 = 0;
                                                int ctrAI = 0;
                                                int ctrShip = 16;
                                                int ctrSend = 0;
                                                string attackAI;

                                                do {
                                                    cout << " ======   AI " << lightRed << "BATTLE" << lightBlue << "SHIP" << defaultColor << "   ======\n" << endl;
                                                    if (ctr % 2 == 0){
                                                        displayBoardPlay(mapBattleShipAi, lightRed, revealShipsCheat, 0, 10);
                                                        displayShipPlay(mapBattleShipAi);
                                                        cout << endl;
                                                        cout << lightRed << setw(16) << "" << "AI" << defaultColor << endl;
                                                        cout << endl;
                                                        cout << "------  \033[93mINTERMEDIATE MODE\033[0m  ------\n" << endl;
                                                        cout << lightBlue << setw(14) << "" << "PLAYER" << defaultColor << endl;
                                                        cout << endl;
                                                        displayShipPlay(mapBattleShip);
                                                        displayBoardPlay(mapBattleShip, lightBlue, revealShipsCheat, 8, 10);
                                                        cout << endl;
                                                    } else {
                                                        displayBoardPlay(mapBattleShipAi, lightRed, revealShipsCheat, 0, 10);
                                                        displayShipPlay(mapBattleShipAi);
                                                        cout << endl;
                                                        cout << lightRed << setw(16) << "" << "AI" << defaultColor << endl;
                                                        cout << endl;
                                                        cout << "------  \033[93mINTERMEDIATE MODE\033[0m  ------\n" << endl;
                                                        cout << lightBlue << setw(14) << "" << "PLAYER" << defaultColor << endl;
                                                        cout << endl;
                                                        displayShipPlay(mapBattleShip);
                                                        displayBoardPlay(mapBattleShip, lightBlue, revealShipsCheat, 8, 10);
                                                        cout << endl;
                                                    }

                                                    if (ctr % 2 == 0){
                                                        ctr++;
                                                        cout << lightBlue << "Player 1" << defaultColor << "'s turn!\nEnter your attack coordinates (ex." << lightRed << " d1, a5" << defaultColor << "): " << lightRed;
                                                        cin >> attack;
                                                        cout << defaultColor;
                                                    } else {
                                                        ctr++;
                                                        attackAI = attackForAI(mapBattleShip, ctrShip, ctrSend, "Medium");
                                                        cout << lightRed << "AI" << defaultColor << "'s turn!\nEntering attack coordinates: " << lightBlue;
                                                        cout << attackAI << endl;
                                                        cout << defaultColor;
                                                        ctrSend++;
                                                        Sleep(1000);
                                                    }
                                                    if (attack == "777"){
                                                        ctr--;
                                                        if (!revealShipsCheat){
                                                            cout << "Cheat activated";
                                                        } else {
                                                            cout << "Cheat deactivated";
                                                        }
                                                        Sleep(500);
                                                        revealShipsCheat = !revealShipsCheat;
                                                    } else if (attack == "x"){
                                                        cout << "Exiting Program";
                                                        for (int i = 0; i < 3; i++){
                                                            cout << ". ";
                                                            Sleep(200);
                                                        }
                                                    } else {
                                                        if (!validateCoordinateInput(attack)){
                                                            ctr--;
                                                            cout << "Invalid Input!";
                                                            Sleep(500);
                                                        } else {
                                                           attackPhase(mapBattleShip, mapBattleShipAi, ctr, ctrShip, ctrWin1, ctrAI, attackAI, attack, "AI");
                                                        }
                                                    }
                                                    system("cls");
                                                } while (attack != "x" && ctrWin1 != 17 && ctrAI != 17);
                                                if(ctrWin1 == 17){
                                                    cout << lightBlue << "You " << defaultColor << "Win !!!";
                                                    Sleep(3000);
                                                    system("cls");
                                                    break;
                                                } else if (ctrAI == 17){
                                                    cout << lightRed << "AI " << defaultColor << "Win !!!";
                                                    Sleep(3000);
                                                    system("cls");
                                                    break;
                                                }
                                            }
                                        break;
                                        }
                                        case 3:{
                                            resetMapAndShips(mapBattleShip);
                                            resetMapAndShips(mapBattleShipAi);
                                            selectedOpt = 0;

                                            do {
                                                displayMenu(selectedOpt, 6, selectShip);

                                                done = false;
                                                positioningShips(mapBattleShip, play, selectShip);
                                            } while (selectShip != 7 && !play);
                                            selectedOpt = 2;
                                            system("cls");

                                            if (play){
                                                placeAllShipsRandomly(mapBattleShipAi);
                                                bool revealShipsCheat = false;
                                                int ctr = 0;
                                                int ctrWin1 = 0;
                                                int ctrAI = 0;
                                                int ctrShip = 16;
                                                int ctrSend = 0;
                                                string attackAI;

                                                do {
                                                    cout << " ======   AI " << lightRed << "BATTLE" << lightBlue << "SHIP" << defaultColor << "   ======\n" << endl;
                                                    if (ctr % 2 == 0){
                                                        displayBoardPlay(mapBattleShipAi, lightRed, revealShipsCheat, 0, 10);
                                                        displayShipPlay(mapBattleShipAi);
                                                        cout << endl;
                                                        cout << lightRed << setw(16) << "" << "AI" << defaultColor << endl;
                                                        cout << endl;
                                                        cout << "--------  \033[95mADVANCED MODE\033[0m  --------\n" << endl;
                                                        cout << lightBlue << setw(14) << "" << "PLAYER" << defaultColor << endl;
                                                        displayShipPlay(mapBattleShip);
                                                        displayBoardPlay(mapBattleShip, lightBlue, revealShipsCheat, 8, 10);
                                                        cout << endl;
                                                    } else {
                                                        displayBoardPlay(mapBattleShipAi, lightRed, revealShipsCheat, 0, 10);
                                                        displayShipPlay(mapBattleShipAi);
                                                        cout << endl;
                                                        cout << lightRed << setw(16) << "" << "AI" << defaultColor << endl;
                                                        cout << endl;
                                                        cout << "--------  \033[95mADVANCED MODE\033[0m  --------\n" << endl;
                                                        cout << lightBlue << setw(14) << "" << "PLAYER" << defaultColor << endl;
                                                        cout << endl;
                                                        displayShipPlay(mapBattleShip);
                                                        displayBoardPlay(mapBattleShip, lightBlue, revealShipsCheat, 8, 10);
                                                        cout << endl;
                                                    }

                                                    if (ctr % 2 == 0){
                                                        ctr++;
                                                        cout << lightBlue << "Player 1" << defaultColor << "'s turn!\nEnter your attack coordinates (ex." << lightRed << " b1, d6" << defaultColor << "): " << lightRed;
                                                        cin >> attack;
                                                        cout << defaultColor;
                                                    } else {
                                                        ctr++;
                                                        attackAI = attackForAI(mapBattleShip, ctrShip, ctrSend, "Hard");
                                                        cout << lightRed << "AI" << defaultColor << "'s turn!\nEntering attack coordinates: " << lightBlue;
                                                        cout << attackAI << endl;
                                                        cout << defaultColor;
                                                        ctrSend++;
                                                        Sleep(1000);
                                                    }
                                                    if (attack == "777"){
                                                        ctr--;
                                                        if (!revealShipsCheat){
                                                            cout << "Cheat activated";
                                                        } else {
                                                            cout << "Cheat deactivated";
                                                        }
                                                        Sleep(500);
                                                        revealShipsCheat = !revealShipsCheat;
                                                    } else if (attack == "x"){
                                                        cout << "Exiting Program";
                                                        for (int i = 0; i < 3; i++){
                                                            cout << ". ";
                                                            Sleep(200);
                                                        }
                                                    } else {
                                                        if (!validateCoordinateInput(attack)){
                                                            ctr--;
                                                            cout << "Invalid Input!";
                                                            Sleep(500);
                                                        } else {
                                                            attackPhase(mapBattleShip, mapBattleShipAi, ctr, ctrShip, ctrWin1, ctrAI, attackAI, attack, "AI");
                                                        }
                                                    }
                                                    system("cls");
                                                } while (attack != "x" && ctrWin1 != 17 && ctrAI != 17);
                                                if(ctrWin1 == 17){
                                                    cout << lightBlue << "You " << defaultColor << "Win !!!";
                                                    Sleep(3000);
                                                    system("cls");
                                                    break;
                                                } else if (ctrAI == 17){
                                                    cout << lightRed << "AI " << defaultColor << "Win !!!";
                                                    Sleep(3000);
                                                    system("cls");
                                                    break;
                                                }
                                            }
                                        break;
                                        }
                                        case 4:{
                                            resetMapAndShips(mapBattleShip);
                                            resetMapAndShips(mapBattleShipAi);
                                            selectedOpt = 0;

                                            do {
                                                displayMenu(selectedOpt, 7, selectShip);

                                                done = false;
                                                positioningShips(mapBattleShip, play, selectShip);
                                            } while (selectShip != 7 && !play);
                                            selectedOpt = 3;
                                            system("cls");

                                            if (play){
                                                placeAllShipsRandomly(mapBattleShipAi);
                                                bool revealShipsCheat = false;
                                                int ctr = 0;
                                                int ctrWin1 = 0;
                                                int ctrAI = 0;
                                                int ctrShip = 16;
                                                string attackAI;

                                                do {
                                                    cout << " ======   AI " << lightRed << "BATTLE" << lightBlue << "SHIP" << defaultColor << "   ======\n" << endl;
                                                    if (ctr % 2 == 0){
                                                        displayBoardPlay(mapBattleShipAi, lightRed, revealShipsCheat, 0, 10);
                                                        displayShipPlay(mapBattleShipAi);
                                                        cout << endl;
                                                        cout << lightRed << setw(16) << "" << "AI" << defaultColor << endl;
                                                        cout << endl;
                                                        cout << "----------  \033[91mGACOR !!!\033[0m  ----------\n" << endl;
                                                        cout << lightBlue << setw(14) << "" << "PLAYER" << defaultColor << endl;
                                                        cout << endl;
                                                        displayShipPlay(mapBattleShip);
                                                        displayBoardPlay(mapBattleShip, lightBlue, revealShipsCheat, 8, 10);
                                                        cout << endl;
                                                    } else {
                                                        displayBoardPlay(mapBattleShipAi, lightRed, revealShipsCheat, 0, 10);
                                                        displayShipPlay(mapBattleShipAi);
                                                        cout << endl;
                                                        cout << lightRed << setw(16) << "" << "AI" << defaultColor << endl;
                                                        cout << endl;
                                                        cout << "----------  \033[91mGACOR !!!\033[0m  ----------\n" << endl;
                                                        cout << lightBlue << setw(14) << "" << "PLAYER" << defaultColor << endl;
                                                        cout << endl;
                                                        displayShipPlay(mapBattleShip);
                                                        displayBoardPlay(mapBattleShip, lightBlue, revealShipsCheat, 8, 10);
                                                        cout << endl;
                                                    }

                                                    if (ctr % 2 == 0){
                                                        ctr++;
                                                        cout << lightBlue << "Player 1" << defaultColor << "'s turn!\nEnter your attack coordinates (ex." << lightRed << " f4, i1" << defaultColor << "): " << lightRed;
                                                        cin >> attack;
                                                        cout << defaultColor;
                                                    } else {
                                                        ctr++;
                                                        attackAI = attackForAI(mapBattleShip, ctrShip, 0, "Gacor");
                                                        cout << lightRed << "AI" << defaultColor << "'s turn!\nEntering attack coordinates: " << lightBlue;
                                                        cout << attackAI << endl;
                                                        cout << defaultColor;
                                                        cout << lightRed << "ezz dek, hehe :V" << defaultColor << endl;
                                                        Sleep(1000);
                                                    }
                                                    if (attack == "777"){
                                                        ctr--;
                                                        if (!revealShipsCheat){
                                                            cout << "Cheat activated";
                                                        } else {
                                                            cout << "Cheat deactivated";
                                                        }
                                                        Sleep(500);
                                                        revealShipsCheat = !revealShipsCheat;
                                                    } else if (attack == "x"){
                                                        cout << "Exiting Program";
                                                        for (int i = 0; i < 3; i++){
                                                            cout << ". ";
                                                            Sleep(200);
                                                        }
                                                    } else {
                                                        if (!validateCoordinateInput(attack)){
                                                            ctr--;
                                                            cout << "Invalid Input!";
                                                            Sleep(500);
                                                        } else {
                                                            attackPhase(mapBattleShip, mapBattleShipAi, ctr, ctrShip, ctrWin1, ctrAI, attackAI, attack, "AI");
                                                        }
                                                    }
                                                    system("cls");
                                                } while (attack != "x" && ctrWin1 != 17 && ctrAI != 17);
                                                if(ctrWin1 == 17){
                                                    cout << lightBlue << "You " << defaultColor << "Win !!!";
                                                    Sleep(3000);
                                                    system("cls");
                                                    break;
                                                } else if (ctrAI == 17){
                                                    cout << lightRed << "AI " << defaultColor << "Win !!!";
                                                    Sleep(3000);
                                                    system("cls");
                                                    break;
                                                }
                                            }
                                        break;
                                        }
                                    }
                            } while (levelGame != 5);
                        selectedOpt = 0;
                        break;
                        }
                        case 2:{
                            play = false;
                            selectedOpt = 0;
                            resetMapAndShips(mapBattleShip);
                            resetMapAndShips(mapBattleShip2);

                            do {
                                displayMenu(selectedOpt, 8, selectShip);

                                done = false;
                                positioningShips(mapBattleShip, play, selectShip);
                            } while (selectShip != 7 && !play);
                            system("cls");

                            if (play){
                                play = false;
                                resetMapAndShips(mapBattleShip2);

                                do {
                                    displayMenu(selectedOpt, 9, selectShip);

                                done = false;
                                positioningShips(mapBattleShip2, play, selectShip);
                            } while (selectShip != 7 && !play);
                            system("cls");

                                if (play){
                                    bool revealShipsCheat = false;
                                    int ctr = 0;
                                    int ctrWin1 = 0;
                                    int ctrWin2 = 0;
                                    int ctrShip;

                                    do {
                                        cout << " ======   VS " << lightRed << "BATTLE" << lightBlue << "SHIP"<< defaultColor << "   ======\n" << endl;
                                        if (ctr % 2 == 0){
                                            displayBoardPlay(mapBattleShip2, lightRed, revealShipsCheat, 0, 10);
                                            displayShipPlay(mapBattleShip2);
                                            cout << endl;
                                            cout << lightRed << setw(13) << "" << "PLAYER 2" << defaultColor << endl;
                                            cout << "---------------------------------" << endl;
                                            cout << lightBlue << setw(13) << "" << "PLAYER 1" << defaultColor << endl;
                                            displayShipPlay(mapBattleShip);
                                            displayBoardPlay(mapBattleShip, lightBlue, revealShipsCheat, 8, 10);
                                            cout << endl;
                                        } else {
                                            displayBoardPlay(mapBattleShip, lightBlue, revealShipsCheat, 0, 10);
                                            displayShipPlay(mapBattleShip);
                                            cout << endl;
                                            cout << lightBlue << setw(13) << "" << "PLAYER 1" << defaultColor << endl;
                                            cout << "---------------------------------" << endl;
                                            cout << lightRed << setw(13) << "" << "PLAYER 2" << defaultColor << endl;
                                            displayShipPlay(mapBattleShip2);
                                            displayBoardPlay(mapBattleShip2, lightRed, revealShipsCheat, 8, 10);
                                            cout << endl;
                                        }

                                        if (ctr % 2 == 0){
                                            ctr++;
                                            cout << lightBlue << "Player 1" << defaultColor << "'s turn!\nEnter your attack coordinates (ex." << lightRed << " b4, i5" << defaultColor << "): " << lightRed;
                                            cin >> attack;
                                            cout << defaultColor;
                                        } else {
                                            ctr++;
                                            cout << lightRed << "Player 2" << defaultColor << "'s turn!\nEnter your attack coordinates (ex." << lightBlue << " b4, i5" << defaultColor << "): " << lightBlue;
                                            cin >> attack;
                                            cout << defaultColor;
                                        }

                                        if (attack == "777"){
                                            ctr--;
                                            if (!revealShipsCheat){
                                                cout << "Cheat activated";
                                            } else {
                                                cout << "Cheat deactivated";
                                            }
                                            Sleep(500);
                                            revealShipsCheat = !revealShipsCheat;
                                        } else if (attack == "x"){
                                            cout << "Exiting Program";
                                            for (int i = 0; i < 3; i++){
                                                cout << ". ";
                                                Sleep(200);
                                            }
                                        } else {
                                            if (!validateCoordinateInput(attack)){
                                                ctr--;
                                                cout << "Invalid Input!";
                                                Sleep(500);
                                            } else {
                                                attackPhase(mapBattleShip, mapBattleShip2, ctr, ctrShip, ctrWin1, ctrWin2, attack, attack, "VS");
                                            }
                                        }
                                        system("cls");
                                    } while (attack != "x" && ctrWin1 != 17 && ctrWin2 != 17);
                                    if(ctrWin1 == 17){
                                        cout << lightBlue << "Player 1 " << defaultColor << "Win !!!";
                                        Sleep(3000);
                                        system("cls");
                                        break;
                                    } else if (ctrWin2 == 17){
                                        cout << lightRed << "Player 2 " << defaultColor << "Win !!!";
                                        Sleep(3000);
                                        system("cls");
                                        break;
                                    }
                                }
                            }
                            selectedOpt = 1;
                            break;
                        }
                    }
                } while (menuPlayGame != 3);
            break;
            }
            case 2:{
                cout << "Leaderboard" << endl;
            break;
            }
            case 3:{
                cout << "History" << endl;
            break;
            }
        }
    } while (menu != 4);
    return 0;
}
