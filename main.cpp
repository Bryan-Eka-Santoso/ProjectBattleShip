#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

char gerak;
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

void displayBoard(){
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

void displayBoardPlay(int mapBattleShip[9][11]) {
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
}

void gerakKapal(char gerak, int &x, int &y, int &shipLength, int modelsShip, bool &isHorizontal) {
    for (int i = 0; i < shipLength; i++) {
        if (isHorizontal) {
            mapBattleShip[y][x + i] = 0;
        } else {
            mapBattleShip[y + i][x] = 0;
        }
    }

    if (gerak == 'w') {
        bool canMove = true;
        for (int i = 0; i < shipLength; i++) {
            if (isHorizontal) {
                if (mapBattleShip[y - 1][x + i] != 0) {
                    canMove = false;
                    break;
                }
            } else {
                if (mapBattleShip[y - 1][x] != 0) {
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
                if (mapBattleShip[y][x - 1] != 0) {
                    canMove = false;
                    break;
                }
            } else {
                if (mapBattleShip[y + i][x - 1] != 0) {
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
                if (mapBattleShip[y + 1][x + i] != 0) {
                    canMove = false;
                    break;
                }
            } else {
                if (mapBattleShip[y + shipLength][x] != 0) {
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
                if (mapBattleShip[y][x + shipLength] != 0) {
                    canMove = false;
                    break;
                }
            } else {
                if (mapBattleShip[y + i][x + 1] != 0) {
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
                if (y + i >= 11 || mapBattleShip[y + i][x] != 0) {
                    canRotate = false;
                    break;
                }
            }
        } else {
            for (int i = 0; i < shipLength; i++) {
                if (x + i >= 9 || mapBattleShip[y][x + i] != 0) {
                    canRotate = false;
                    break;
                }
            }
        }

        if (canRotate) {
            for (int i = 0; i < shipLength; i++)
                mapBattleShip[y][x + i] = 0;
            isHorizontal = !isHorizontal;
        }
    }

    for (int i = 0; i < shipLength; i++) {
        if (isHorizontal) {
            mapBattleShip[y][x + i] = modelsShip;
        } else {
            mapBattleShip[y + i][x] = modelsShip;
        }
    }
}

void spawnShip(int shipLength, int &x, int &y, int modelsShip, bool &isHorizontal){
    for(int i = 0; i < shipLength; i++){
        if (isHorizontal)
            mapBattleShip[y][x + i] = modelsShip;
        else
            mapBattleShip[y + i][x] = modelsShip;
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
                                                                spawnShip(destroyerShipLength, destroyerX, destroyerY, destroyer, isHrDestroyer);

                                                                cout << "== Destroyer Ship \033[31m**\033[0m ==" << endl << endl;

                                                                displayBoard();

                                                                cout << endl;
                                                                cout << "Press w/a/s/d to move your ship" << endl;
                                                                cout << "Press enter to save the position of ship" << endl;
                                                                cout << "Press r to rotate your ship" << endl;

                                                                gerak = getch();

                                                                gerakKapal(gerak, destroyerX, destroyerY, destroyerShipLength, destroyer, isHrDestroyer);

                                                                if (gerak == '\r'){
                                                                    done = true;
                                                                }

                                                            system("cls");
                                                            } while (!done);
                                                        break;
                                                        }
                                                        case 2:{
                                                            do {
                                                                spawnShip(submarineShipLength, submarineX, submarineY, submarine, isHrSubmarine);

                                                                cout << "== Submarine Ship \033[32m***\033[0m ==" << endl << endl;

                                                                displayBoard();

                                                                cout << endl;
                                                                cout << "Press w/a/s/d to move your ship" << endl;
                                                                cout << "Press enter to save the position of ship" << endl;
                                                                cout << "Press r to rotate your ship" << endl;

                                                                gerak = getch();

                                                                gerakKapal(gerak, submarineX, submarineY, submarineShipLength, submarine, isHrSubmarine);

                                                                if (gerak == '\r'){
                                                                    done = true;
                                                                }

                                                            system("cls");
                                                            } while (!done);
                                                        break;
                                                        }
                                                        case 3:{
                                                            do {
                                                                spawnShip(cruiserShipLength, cruiserX, cruiserY, cruiser, isHrCruiser);

                                                                cout << "== Cruiser Ship \033[33m***\033[0m ==" << endl << endl;

                                                                displayBoard();

                                                                cout << endl;
                                                                cout << "Press w/a/s/d to move your ship" << endl;
                                                                cout << "Press enter to save the position of ship" << endl;
                                                                cout << "Press r to rotate your ship" << endl;

                                                                gerak = getch();

                                                                gerakKapal(gerak, cruiserX, cruiserY, cruiserShipLength, cruiser, isHrCruiser);

                                                                if (gerak == '\r'){
                                                                    done = true;
                                                                }

                                                            system("cls");
                                                            } while (!done);
                                                        break;
                                                        }
                                                        case 4:{
                                                            do {
                                                                spawnShip(battleshipShipLength, battleshipX, battleshipY, battleship, isHrBattleship);

                                                                cout << "== Battle Ship \033[34m****\033[0m ==" << endl << endl;

                                                                displayBoard();

                                                                cout << endl;
                                                                cout << "Press w/a/s/d to move your ship" << endl;
                                                                cout << "Press enter to save the position of ship" << endl;
                                                                cout << "Press r to rotate your ship" << endl;

                                                                gerak = getch();

                                                                gerakKapal(gerak, battleshipX, battleshipY, battleshipShipLength, battleship, isHrBattleship);

                                                                if (gerak == '\r'){
                                                                    done = true;
                                                                }

                                                            system("cls");
                                                            } while (!done);
                                                        break;
                                                        }
                                                        case 5:{
                                                            do {
                                                                spawnShip(carrierShipLength, carrierX, carrierY, carrier, isHrCarrier);

                                                                cout << "== Carrier Ship \033[35m*****\033[0m ==" << endl << endl;

                                                                displayBoard();

                                                                cout << endl;
                                                                cout << "Press w/a/s/d to move your ship" << endl;
                                                                cout << "Press enter to save the position of ship" << endl;
                                                                cout << "Press r to rotate your ship" << endl;

                                                                gerak = getch();

                                                                gerakKapal(gerak, carrierX, carrierY, carrierShipLength, carrier, isHrCarrier);

                                                                if (gerak == '\r'){
                                                                    done = true;
                                                                }

                                                            system("cls");
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
                                                    cout << "== Welcome to the game battleship ==" << endl << endl;
                                                    displayBoardPlay(mapBattleShip);
                                                    cout << endl;
                                                    displayBoardPlay(mapBattleShip);
                                                    cout << endl;
                                                }
                                            break;
                                            }
                                        }
                                } while (levelGame != 0);
                            break;
                            }
                            case 2:{
                                do {
                                    cout << "== You selected 2 player game ==" << endl;
                                    cout << "Please player 1 set up the position your ship :" << endl;
                                    cout << "1. " << "\033[31m**\033[0m" << " Destroyer" << endl;
                                    cout << "2. " << "\033[32m***\033[0m" << " Submarine" << endl;
                                    cout << "3. " << "\033[33m***\033[0m" << " Cruiser" << endl;
                                    cout << "4. " << "\033[34m****\033[0m" << " Battleship" << endl;
                                    cout << "5. " << "\033[35m*****\033[0m" << " Carrier" << endl;
                                    cout << "6. " << "Next to set up ship the player 2" << endl;
                                    cout << "0. Back" << endl;

                                    do {
                                        cout << ">> ";
                                        cin >> selectShip;
                                    } while (selectShip < 0 || selectShip > 6);
                                    system("cls");
                                } while (selectShip != 0);
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
