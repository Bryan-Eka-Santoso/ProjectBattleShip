#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

char gerak;
char playInGame;
string attack;
string lightRed = "\033[091m", lightBlue = "\033[094m";
string defaultColor = "\033[0m";
int destroyerShipLength = 2;
int submarineShipLength = 3;
int cruiserShipLength = 3;
int battleshipShipLength = 4;
int carrierShipLength = 5;
int destroyerY = 1, destroyerX = 1;
int submarineY = 1, submarineX = 1;
int cruiserY = 1, cruiserX = 1;
int battleshipY = 1, battleshipX = 1;
int carrierX = 1, carrierY = 1;
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
                cout << "# ";
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

void displayBoardPlay(int mapBattleShip[9][11], string color, bool &cheat){
    if (!cheat){
        cout << color;
        for(int i = 0; i < 9; i++) {
            if (i == 0 || i == 8) {
                for (int j = 0; j < 11; j++) {
                    if(j == 0 || j == 10){
                        cout << "   ";
                    } else {
                        char letter = 'a' + j - 1;
                        cout << " " << letter << " ";
                    }
                }
            } else {
                for (int j = 0; j < 11; j++) {
                    if (mapBattleShip[i][j] == 1) {
                        cout << " " << i << " ";
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
                        cout << "   ";
                    } else {
                        char letter = 'a' + j - 1;
                        cout << " " << letter << " ";
                    }
                }
            } else {
                for (int j = 0; j < 11; j++) {
                    if (mapBattleShip[i][j] == 1) {
                        cout << " " << i << " ";
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
        if (isHorizontal)
            mapBatShip[y][x + i] = modelsShip;
        else
            mapBatShip[y + i][x] = modelsShip;
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

void displayMenu (int selectedOption, vector<string> &menu){
    for (int i = 0; i < menu.size(); i++) {
        if (i == selectedOption) {
            cout << "> " << menu[i] << endl;
        } else {
            cout << "  " << menu[i] << endl;
        }
    }
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
        {2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
    };

    do {
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 29; j++){
            if (textMenu[i][j] == 1){
                cout << "* ";
            } else if (textMenu[i][j] == 2){
                cout << "# ";
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
                                                do {
                                                    cout << "== You selected very hard difficulty ==" << endl;
                                                    cout << "Please set up the position your ship :" << endl;
                                                    cout << "1. " << "\033[31m**\033[0m" << " Destroyer" << endl;
                                                    cout << "2. " << "\033[32m***\033[0m" << " Submarine" << endl;
                                                    cout << "3. " << "\033[33m***\033[0m" << " Cruiser" << endl;
                                                    cout << "4. " << "\033[34m****\033[0m" << " Battleship" << endl;
                                                    cout << "5. " << "\033[35m*****\033[0m" << " Carrier" << endl;
                                                    cout << "6. Finish" << endl;
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
                                                    do {
                                                        cout << "== Welcome to the game battleship ==\n" << endl;
                                                        displayBoardPlay(mapBattleShipAi, lightRed, revealShipsCheat);
                                                        cout << endl;
                                                        displayBoardPlay(mapBattleShip, lightBlue, revealShipsCheat);
                                                        cout << endl;
                                                        cout << "Enter your attack coordinates: ";
                                                        cin >> attack;
                                                        if (attack == "cheatBMK"){
                                                            if (!revealShipsCheat){
                                                                cout << "Cheat activated" << endl;
                                                            } else {
                                                                cout << "Cheat deactivated" << endl;
                                                            }
                                                            Sleep(500);
                                                            revealShipsCheat = !revealShipsCheat;
                                                        }
                                                        system("cls");
                                                    } while (attack != "x");
                                                }
                                            break;
                                            }
                                        }
                                } while (levelGame != 0);
                            break;
                            }
                            case 2:{
                                bool play = false;
                                do {
                                    cout << "== Battle Ship Versus Mode ==" << endl;
                                    cout << "Please player 1 set up the position your ship :" << endl;
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
                                    int destroyerY = 1, destroyerX = 1;
                                    int submarineY = 1, submarineX = 1;
                                    int cruiserY = 1, cruiserX = 1;
                                    int battleshipY = 1, battleshipX = 1;
                                    int carrierX = 1, carrierY = 1;
                                    bool isHrDestroyer = true, isHrSubmarine = true, isHrCruiser = true, isHrBattleship = true, isHrCarrier = true;
                                    do {
                                        cout << "== Battle Ship Versus Mode ==" << endl;
                                        cout << "Please player 2 set up the position your ship :" << endl;
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
                                        do {
                                            cout << "== Welcome to the game battleship ==\n" << endl;
                                            displayBoardPlay(mapBattleShip2, lightRed, revealShipsCheat);
                                            cout << endl;
                                            displayBoardPlay(mapBattleShip, lightBlue, revealShipsCheat);
                                            cout << endl;
                                            cout << "Enter your attack coordinates: ";
                                            cin >> attack;
                                            if (attack == "cheatBMK"){
                                                if (!revealShipsCheat){
                                                    cout << "Cheat activated" << endl;
                                                } else {
                                                    cout << "Cheat deactivated" << endl;
                                                }
                                                Sleep(500);
                                                revealShipsCheat = !revealShipsCheat;
                                            }
                                            system("cls");
                                        } while (attack != "x");
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
