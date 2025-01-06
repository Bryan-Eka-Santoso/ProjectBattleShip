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
string attack, defaultColor = "\033[0m", lightRed = "\033[091m", lightBlue = "\033[094m", lightBlack = "\033[090m";
int destroyerShipLength = 2, submarineShipLength = 3, cruiserShipLength = 3, battleshipShipLength = 4, carrierShipLength = 5;
int destroyerY = 1, destroyerX = 1, submarineY = 1, submarineX = 1, cruiserY = 1, cruiserX = 1, battleshipY = 1, battleshipX = 1, carrierX = 1, carrierY = 1;
int destroyer = 2, submarine = 3, cruiser = 4, battleship = 5, carrier = 6;
bool isHrDestroyer = true, isHrSubmarine = true, isHrCruiser = true, isHrBattleship = true, isHrCarrier = true;

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
                cout << ". ";
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

void shipRandomizedDeployer(int &x, int &y, int shipLength, int modelShip, int mapBatShip[9][11], string name, bool &isHr){
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

void shipRandomizer(int mapBatShip[9][11]){
    srand(time(0));

    for (int i = 1; i < 8; i++){
        for (int j = 1; j < 10; j++){
            if (mapBatShip[i][j] == 2 || mapBatShip[i][j] == 3 || mapBatShip[i][j] == 4 || mapBatShip[i][j] == 5 || mapBatShip[i][j] == 6)
                mapBatShip[i][j] = 0;
        }
    }
    isHrDestroyer = true; isHrSubmarine = true; isHrCruiser = true; isHrBattleship = true; isHrCarrier = true;

    shipRandomizedDeployer(destroyerX, destroyerY, destroyerShipLength, destroyer, mapBatShip, "Destroyer", isHrDestroyer);
    shipRandomizedDeployer(submarineX, submarineY, submarineShipLength, submarine, mapBatShip, "Submarine", isHrSubmarine);
    shipRandomizedDeployer(cruiserX, cruiserY, cruiserShipLength, cruiser, mapBatShip, "Cruiser", isHrCruiser);
    shipRandomizedDeployer(battleshipX, battleshipY, battleshipShipLength, battleship, mapBatShip, "Battleship", isHrBattleship);
    shipRandomizedDeployer(carrierX, carrierY, carrierShipLength, carrier, mapBatShip, "Carrier", isHrCarrier);
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
        shipRandomizer(mapBatShip);
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

    cout << endl;
    cout << setw(5) << " " << destroyerDisplay << " " << submarineDisplay << "  " << cruiserDisplay << "  " << battleshipDisplay << " " << carrierDisplay;
    cout << endl;
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

    do {
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 29; j++){
            if (textMenu[i][j] == 1){
                cout << lightRed << "* " << defaultColor;
            } else if (textMenu[i][j] == 2){
                cout << lightBlack << "# " << defaultColor;
            } else if (textMenu[i][j] == 3){
                cout << lightBlue << "* " << defaultColor;;
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    cout << endl;
    cout << "== Welcome To BattleShip Game ==" << endl;
    cout << "1. Play Game" << endl;
    cout << "2. Leaderboard" << endl;
    cout << "3. History Game" << endl;
    cout << "0. Exit" << endl;
        do {
            cout << ">> ";
            cin >> menu;
        } while (menu < 0 || menu > 3);
        system("cls");

        switch(menu){
            case 1:{
                do {
                    cout << "== Play Game ==" << endl;
                    cout << "1. VS AI" << endl;
                    cout << "2. 2 Player" << endl;
                    cout << "0. Back" << endl;
                        do {
                            cout << ">> ";
                            cin >> menuPlayGame;
                        } while (menuPlayGame < 0 || menuPlayGame > 2);
                        system("cls");

                        switch(menuPlayGame){
                            case 1:{
                                do {
                                    cout << "== Choose The Difficulty ==" << endl;
                                    cout << "1. Easy" << endl;
                                    cout << "2. Medium" << endl;
                                    cout << "3. Hard" << endl;
                                    cout << "4. Very Hard" << endl;
                                    cout << "0. Back" << endl;
                                    do {
                                        cout << ">> ";
                                        cin >> levelGame;
                                    } while (levelGame < 0 || levelGame > 4);
                                    system("cls");

                                        switch(levelGame){
                                            case 1:{

                                            break;
                                            }
                                            case 2:{

                                            break;
                                            }
                                            case 3:{

                                            break;
                                            }
                                            case 4:{
                                                bool play = false;
                                                risetCoordinate(isHrDestroyer, destroyerX, destroyerY);
                                                risetCoordinate(isHrSubmarine, submarineX, submarineY);
                                                risetCoordinate(isHrCruiser, cruiserX, cruiserY);
                                                risetCoordinate(isHrBattleship, battleshipX, battleshipY);
                                                risetCoordinate(isHrCarrier, carrierX, carrierY);
                                                risetMap(mapBattleShip);

                                                do {
                                                    cout << "== You selected very hard difficulty ==" << endl;
                                                    cout << "Please set up the position your ship :" << endl;
                                                    cout << "1. " << "\033[31m**\033[0m" << " Destroyer" << endl;
                                                    cout << "2. " << "\033[32m***\033[0m" << " Submarine" << endl;
                                                    cout << "3. " << "\033[33m***\033[0m" << " Cruiser" << endl;
                                                    cout << "4. " << "\033[34m****\033[0m" << " Battleship" << endl;
                                                    cout << "5. " << "\033[35m*****\033[0m" << " Carrier" << endl;
                                                    cout << "6. Play Game" << endl;
                                                    cout << "0. Back" << endl;

                                                    do {
                                                        cout << ">> ";
                                                        cin >> selectShip;
                                                    } while (selectShip < 0 || selectShip > 6);
                                                    system("cls");

                                                    bool done = false;
                                                    switch(selectShip){
                                                        case 1:{
                                                            do {
                                                                deployAndOperateShip(gerak, '1', destroyerShipLength, destroyerX, destroyerY, destroyer, isHrDestroyer, done, mapBattleShip, "Destroyer");
                                                            } while (!done);
                                                        break;
                                                        }
                                                        case 2:{
                                                            do {
                                                                deployAndOperateShip(gerak, '2', submarineShipLength, submarineX, submarineY, submarine, isHrSubmarine, done, mapBattleShip, "Submarine");
                                                            } while (!done);
                                                        break;
                                                        }
                                                        case 3:{
                                                            do {
                                                                deployAndOperateShip(gerak, '3', cruiserShipLength, cruiserX, cruiserY, cruiser, isHrCruiser, done, mapBattleShip, "Cruiser");
                                                            } while (!done);
                                                        break;
                                                        }
                                                        case 4:{
                                                            do {
                                                                deployAndOperateShip(gerak, '4', battleshipShipLength, battleshipX, battleshipY, battleship, isHrBattleship, done, mapBattleShip, "Battle");
                                                            } while (!done);
                                                        break;
                                                        }
                                                        case 5:{
                                                            do {
                                                                deployAndOperateShip(gerak, '5', carrierShipLength, carrierX, carrierY, carrier, isHrCarrier, done, mapBattleShip, "Carrier");
                                                            } while (!done);
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
                                                                cout << "Please set up all postiton your ship" << endl;
                                                                Sleep(1000);
                                                                system("cls");
                                                            }
                                                            break;
                                                        }
                                                    }
                                                } while (selectShip != 0 && !play);
                                                system("cls");

                                                if (play){
                                                    shipRandomizer(mapBattleShipAi);
                                                    bool revealShipsCheat = false;
                                                    int ctr = 0;
                                                    int ctrWin1 = 0;
                                                    int ctrWin2 = 0;

                                                    do {
                                                        cout << " ======   AI " << lightRed << "BATTLE" << lightBlue << "SHIP" << defaultColor << "   ======\n" << endl;
                                                        if (ctr % 2 == 0){
                                                            displayBoardPlay(mapBattleShipAi, lightRed, revealShipsCheat, 0, 10);
                                                            cout << lightRed << setw(16) << "" << "AI" << defaultColor << endl;
                                                            cout << endl;
                                                            cout << "---------------------------------\n" << endl;
                                                            cout << lightBlue << setw(14) << "" << "PLAYER" << defaultColor << endl;
                                                            displayBoardPlay(mapBattleShip, lightBlue, revealShipsCheat, 8, 10);
                                                            cout << endl;
                                                        } else {
                                                            displayBoardPlay(mapBattleShipAi, lightRed, revealShipsCheat, 0, 10);
                                                            cout << lightRed << setw(16) << "" << "AI" << defaultColor << endl;
                                                            cout << endl;
                                                            cout << "---------------------------------\n" << endl;
                                                            cout << lightBlue << setw(14) << "" << "PLAYER" << defaultColor << endl;
                                                            displayBoardPlay(mapBattleShip, lightBlue, revealShipsCheat, 8, 10);
                                                            cout << endl;
                                                        }

                                                        if (ctr % 2 == 0){
                                                            ctr++;
                                                            cout << lightBlue << "Player 1" << defaultColor << "'s turn!\nEnter your attack coordinates (" << lightRed << "xy" << defaultColor << "): ";
                                                            cin >> attack;
                                                        } else {
                                                            ctr++;
                                                            cout << lightRed << "Player 2" << defaultColor << "'s turn!\nEnter your attack coordinates (" << lightBlue << "xy" << defaultColor << "): ";
                                                            cin >> attack;
                                                        }
                                                        if (attack == "777"){
                                                            ctr--;
                                                            if (!revealShipsCheat){
                                                                cout << "Cheat activated" << endl;
                                                            } else {
                                                                cout << "Cheat deactivated" << endl;
                                                            }
                                                            Sleep(500);
                                                            revealShipsCheat = !revealShipsCheat;
                                                        } else {
                                                            if (!validateCoordinateInput(attack)){
                                                                ctr--;
                                                                cout << "Invalid Input!" << endl;
                                                                Sleep(500);
                                                            } else {

                                                                int y = processCoordinates(attack) % 10;
                                                                int x = processCoordinates(attack) / 10 % 10;

                                                                if(ctr % 2 == 0){
                                                                    if(mapBattleShip[y][x] == 0 || mapBattleShip[y][x] == 1){
                                                                        mapBattleShip[y][x] = 12;
                                                                        cout << "No ship was hit!" << endl;
                                                                    } else if (mapBattleShip[y][x] >= 2 && mapBattleShip[y][x] <= 6){
                                                                        if(mapBattleShip[y][x] == 2){
                                                                            mapBattleShip[y][x] = 7;
                                                                        } else if (mapBattleShip[y][x] == 3){
                                                                            mapBattleShip[y][x] = 8;
                                                                        } else if (mapBattleShip[y][x] == 4){
                                                                            mapBattleShip[y][x] = 9;
                                                                        } else if (mapBattleShip[y][x] == 5){
                                                                            mapBattleShip[y][x] = 10;
                                                                        } else if (mapBattleShip[y][x] == 6){
                                                                            mapBattleShip[y][x] = 11;
                                                                        }
                                                                        ctr--;
                                                                        ctrWin1++;
                                                                        cout << 17 - ctrWin1 << " more points to go!" << endl;
                                                                    } else {
                                                                        ctr--;
                                                                        cout << "Invalid coordinates!" << endl;
                                                                    }
                                                                    Sleep(500);
                                                                } else {
                                                                   if(mapBattleShipAi[y][x] == 0 || mapBattleShipAi[y][x] == 1){
                                                                        mapBattleShipAi[y][x] = 12;
                                                                        cout << "No ship was hit!" << endl;
                                                                    } else if (mapBattleShipAi[y][x] >= 2 && mapBattleShipAi[y][x] <= 6){
                                                                        if(mapBattleShip[y][x] == 2){
                                                                            mapBattleShip[y][x] = 7;
                                                                        } else if (mapBattleShip[y][x] == 3){
                                                                            mapBattleShip[y][x] = 8;
                                                                        } else if (mapBattleShip[y][x] == 4){
                                                                            mapBattleShip[y][x] = 9;
                                                                        } else if (mapBattleShip[y][x] == 5){
                                                                            mapBattleShip[y][x] = 10;
                                                                        } else if (mapBattleShip[y][x] == 6){
                                                                            mapBattleShip[y][x] = 11;
                                                                        }
                                                                        ctr--;
                                                                        ctrWin2++;
                                                                        cout << 17 - ctrWin2 << " more points to go!" << endl;
                                                                    } else {
                                                                        ctr--;
                                                                        cout << "Invalid coordinates!" << endl;
                                                                    }
                                                                    Sleep(500);
                                                                }
                                                            }
                                                        }
                                                        system("cls");
                                                    } while (attack != "x" && ctrWin1 != 17 && ctrWin2 != 17);
                                                    if(ctrWin1 == 17){
                                                        cout << lightBlue << "You " << defaultColor << "Win !!!";
                                                        Sleep(3000);
                                                        system("cls");
                                                        break;
                                                    } else if (ctrWin2 == 17){
                                                        cout << lightRed << "AI " << defaultColor << "Win !!!";
                                                        Sleep(3000);
                                                        system("cls");
                                                        break;
                                                    }
                                                }
                                            break;
                                            }
                                        }
                                } while (levelGame != 0);
                            break;
                            }
                            case 2:{
                                bool play = false;
                                risetCoordinate(isHrDestroyer, destroyerX, destroyerY);
                                risetCoordinate(isHrSubmarine, submarineX, submarineY);
                                risetCoordinate(isHrCruiser, cruiserX, cruiserY);
                                risetCoordinate(isHrBattleship, battleshipX, battleshipY);
                                risetCoordinate(isHrCarrier, carrierX, carrierY);
                                risetMap(mapBattleShip);

                                do {
                                    cout << "== BattleShip Versus Mode ==" << endl;
                                    cout << "Please " << lightBlue << "player 1" << defaultColor << " set up the position your ship :" << endl;
                                    cout << "1. " << "\033[31m**\033[0m" << " Destroyer" << endl;
                                    cout << "2. " << "\033[32m***\033[0m" << " Submarine" << endl;
                                    cout << "3. " << "\033[33m***\033[0m" << " Cruiser" << endl;
                                    cout << "4. " << "\033[34m****\033[0m" << " Battleship" << endl;
                                    cout << "5. " << "\033[35m*****\033[0m" << " Carrier" << endl;
                                    cout << "6. " << "Finish" << endl;
                                    cout << "0. Back" << endl;

                                    do {
                                        cout << ">> ";
                                        cin >> selectShip;
                                    } while (selectShip < 0 || selectShip > 6);
                                    system("cls");

                                    bool done = false;
                                    switch(selectShip){
                                        case 1:{
                                            do {
                                                deployAndOperateShip(gerak, '1', destroyerShipLength, destroyerX, destroyerY, destroyer, isHrDestroyer, done, mapBattleShip, "Destroyer");
                                            } while (!done);
                                        break;
                                        }
                                        case 2:{
                                            do {
                                                deployAndOperateShip(gerak, '2', submarineShipLength, submarineX, submarineY, submarine, isHrSubmarine, done, mapBattleShip, "Submarine");
                                            } while (!done);
                                        break;
                                        }
                                        case 3:{
                                            do {
                                                deployAndOperateShip(gerak, '3', cruiserShipLength, cruiserX, cruiserY, cruiser, isHrCruiser, done, mapBattleShip, "Cruiser");
                                            } while (!done);
                                        break;
                                        }
                                        case 4:{
                                            do {
                                                deployAndOperateShip(gerak, '4', battleshipShipLength, battleshipX, battleshipY, battleship, isHrBattleship, done, mapBattleShip, "Battle");
                                            } while (!done);
                                        break;
                                        }
                                        case 5:{
                                            do {
                                                deployAndOperateShip(gerak, '5', carrierShipLength, carrierX, carrierY, carrier, isHrCarrier, done, mapBattleShip, "Carrier");
                                            } while (!done);
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
                                                cout << "Please set up all postiton your ship" << endl;
                                                Sleep(1000);
                                                system("cls");
                                            }
                                            break;
                                        }
                                    }
                                } while (selectShip != 0 && !play);
                                system("cls");

                                if (play){
                                    play = false;
                                    risetCoordinate(isHrDestroyer, destroyerX, destroyerY);
                                    risetCoordinate(isHrSubmarine, submarineX, submarineY);
                                    risetCoordinate(isHrCruiser, cruiserX, cruiserY);
                                    risetCoordinate(isHrBattleship, battleshipX, battleshipY);
                                    risetCoordinate(isHrCarrier, carrierX, carrierY);
                                    risetMap(mapBattleShip2);

                                    do {
                                        cout << "== BattleShip Versus Mode ==" << endl;
                                        cout << "Please " << lightRed << "player 2" << defaultColor << " set up the position your ship :" << endl;
                                        cout << "1. " << "\033[31m**\033[0m" << " Destroyer" << endl;
                                        cout << "2. " << "\033[32m***\033[0m" << " Submarine" << endl;
                                        cout << "3. " << "\033[33m***\033[0m" << " Cruiser" << endl;
                                        cout << "4. " << "\033[34m****\033[0m" << " Battleship" << endl;
                                        cout << "5. " << "\033[35m*****\033[0m" << " Carrier" << endl;
                                        cout << "6. " << "Play Game" << endl;
                                        cout << "0. Back" << endl;

                                    do {
                                        cout << ">> ";
                                        cin >> selectShip;
                                    } while (selectShip < 0 || selectShip > 6);
                                    system("cls");

                                    bool done = false;
                                    switch(selectShip){
                                        case 1:{
                                            do {
                                                deployAndOperateShip(gerak, '1', destroyerShipLength, destroyerX, destroyerY, destroyer, isHrDestroyer, done, mapBattleShip2, "Destroyer");
                                            } while (!done);
                                        break;
                                        }
                                        case 2:{
                                            do {
                                                deployAndOperateShip(gerak, '2', submarineShipLength, submarineX, submarineY, submarine, isHrSubmarine, done, mapBattleShip2, "Submarine");
                                            } while (!done);
                                        break;
                                        }
                                        case 3:{
                                            do {
                                                deployAndOperateShip(gerak, '3', cruiserShipLength, cruiserX, cruiserY, cruiser, isHrCruiser, done, mapBattleShip2, "Cruiser");
                                            } while (!done);
                                        break;
                                        }
                                        case 4:{
                                            do {
                                                deployAndOperateShip(gerak, '4', battleshipShipLength, battleshipX, battleshipY, battleship, isHrBattleship, done, mapBattleShip2, "Battle");
                                            } while (!done);
                                        break;
                                        }
                                        case 5:{
                                            do {
                                                deployAndOperateShip(gerak, '5', carrierShipLength, carrierX, carrierY, carrier, isHrCarrier, done, mapBattleShip2, "Carrier");
                                            } while (!done);
                                        break;
                                        }
                                        case 6:{
                                        int ctr = 0;

                                            for(int i = 0; i < 9; i++){
                                                for(int j = 0; j < 11; j++){
                                                    if(mapBattleShip2[i][j] == 0){
                                                        ctr++;
                                                    }
                                                }
                                            }

                                            if (ctr == 46){
                                                play = true;
                                            } else {
                                                cout << "Please set up all postiton your ship" << endl;
                                                Sleep(1000);
                                                system("cls");
                                            }
                                            break;
                                        }
                                    }
                                } while (selectShip != 0 && !play);
                                system("cls");

                                    if (play){
                                        bool revealShipsCheat = false;
                                        int ctr = 0;
                                        int ctrWin1 = 0;
                                        int ctrWin2 = 0;

                                        do {
                                            cout << " ======   VS " << lightRed << "BATTLE" << lightBlue << "SHIP"<< defaultColor << "   ======\n" << endl;
                                            if (ctr % 2 == 0){
                                                displayBoardPlay(mapBattleShip2, lightRed, revealShipsCheat, 0, 10);
                                                cout << lightRed << setw(13) << "" << "PLAYER 2" << defaultColor << endl;
                                                displayShipPlay(mapBattleShip2);
                                                cout << endl;
                                                cout << "---------------------------------\n" << endl;
                                                cout << lightBlue << setw(13) << "" << "PLAYER 1" << defaultColor << endl;
                                                displayShipPlay(mapBattleShip);
                                                displayBoardPlay(mapBattleShip, lightBlue, revealShipsCheat, 8, 10);
                                                cout << endl;
                                            } else {
                                                displayBoardPlay(mapBattleShip, lightBlue, revealShipsCheat, 0, 10);
                                                cout << lightBlue << setw(13) << "" << "PLAYER 1" << defaultColor << endl;
                                                displayShipPlay(mapBattleShip);
                                                cout << endl;
                                                cout << "---------------------------------\n" << endl;
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
                                                    cout << "Cheat activated" << endl;
                                                } else {
                                                    cout << "Cheat deactivated" << endl;
                                                }
                                                Sleep(500);
                                                revealShipsCheat = !revealShipsCheat;
                                            } else {
                                                if (!validateCoordinateInput(attack)){
                                                    ctr--;
                                                    cout << "Invalid Input!" << endl;
                                                    Sleep(500);
                                                } else {

                                                    int y = processCoordinates(attack) % 10;
                                                    int x = processCoordinates(attack) / 10 % 10;

                                                    if(ctr % 2 == 0){
                                                        if(mapBattleShip[y][x] == 0 || mapBattleShip[y][x] == 1){
                                                            mapBattleShip[y][x] = 12;
                                                            cout << "No ship was hit!" << endl;
                                                        } else if (mapBattleShip[y][x] >= 2 && mapBattleShip[y][x] <= 6){
                                                            if(mapBattleShip[y][x] == 2){
                                                                mapBattleShip[y][x] = 7;
                                                            } else if (mapBattleShip[y][x] == 3){
                                                                mapBattleShip[y][x] = 8;
                                                            } else if (mapBattleShip[y][x] == 4){
                                                                mapBattleShip[y][x] = 9;
                                                            } else if (mapBattleShip[y][x] == 5){
                                                                mapBattleShip[y][x] = 10;
                                                            } else if (mapBattleShip[y][x] == 6){
                                                                mapBattleShip[y][x] = 11;
                                                            }
                                                            ctr--;
                                                            ctrWin1++;
                                                            cout << 17 - ctrWin1 << " more points to go!" << endl;
                                                        } else {
                                                            ctr--;
                                                            cout << "Invalid coordinates!" << endl;
                                                        }
                                                        Sleep(500);
                                                    } else {
                                                       if(mapBattleShip2[y][x] == 0 || mapBattleShip2[y][x] == 1){
                                                            mapBattleShip2[y][x] = 12;
                                                            cout << "No ship was hit!" << endl;
                                                        } else if (mapBattleShip2[y][x] >= 2 && mapBattleShip2[y][x] <= 6){
                                                            if(mapBattleShip2[y][x] == 2){
                                                                mapBattleShip2[y][x] = 7;
                                                            } else if (mapBattleShip2[y][x] == 3){
                                                                mapBattleShip2[y][x] = 8;
                                                            } else if (mapBattleShip2[y][x] == 4){
                                                                mapBattleShip2[y][x] = 9;
                                                            } else if (mapBattleShip2[y][x] == 5){
                                                                mapBattleShip2[y][x] = 10;
                                                            } else if (mapBattleShip2[y][x] == 6){
                                                                mapBattleShip2[y][x] = 11;
                                                            }
                                                            ctr--;
                                                            ctrWin2++;
                                                            cout << 17 - ctrWin2 << " more points to go!" << endl;
                                                        } else {
                                                            ctr--;
                                                            cout << "Invalid coordinates!" << endl;
                                                        }
                                                        Sleep(500);
                                                    }
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
                                break;
                            }
                        }
                } while (menuPlayGame != 0);
            break;
            }
            case 2:{
                cout << "Leaderboard" << endl;
            break;
            }
            case 3:{
                cout << "History Game" << endl;
            break;
            }
        }
    } while (menu !=0);
    return 0;
}
