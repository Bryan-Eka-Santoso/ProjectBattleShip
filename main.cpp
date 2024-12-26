#include <iostream>
#include <conio.h>

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

void gerakKapal(char gerak, int &x, int &y , int shipLength, int modelsShip){
    for(int i = 0; i < shipLength; i++){
        mapBattleShip[y][x + i] = 0;
    }

    if(gerak == 'w'){
        bool canMove = true;

        for (int i = 0; i < shipLength; i++) {
            if (mapBattleShip[y - 1][x + i] != 0) {
                canMove = false;
                break;
                }
        }

        if (canMove) {
            y--;
        }
    } else if (gerak == 'a'){
        if(mapBattleShip[y][x-1] == 0){
            x--;
        }
    } else if (gerak == 's'){
        bool canMove = true;

        for (int i = 0; i < shipLength; i++) {
            if (mapBattleShip[y + 1][x + i] != 0) {
                canMove = false;
                break;
                }
        }

        if (canMove) {
            y++;
        }
    } else if (gerak == 'd'){
        if(mapBattleShip[y][x+shipLength] == 0){
            x++;
        }
    } else if (gerak == 'r'){

    }

    for(int i = 0; i < shipLength; i++) {
        mapBattleShip[y][x + i] = modelsShip;
    }
}

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
                                                do {
                                                    cout << "== You selected very hard difficulty ==" << endl;
                                                    cout << "Please set up the position your ship :" << endl;
                                                    cout << "1. " << "\033[31m**\033[0m" << " Destroyer" << endl;
                                                    cout << "2. " << "\033[32m***\033[0m" << " Submarine" << endl;
                                                    cout << "3. " << "\033[33m***\033[0m" << " Cruiser" << endl;
                                                    cout << "4. " << "\033[34m****\033[0m" << " Battleship" << endl;
                                                    cout << "5. " << "\033[35m*****\033[0m" << " Carrier" << endl;
                                                    cout << "0. Back" << endl;

                                                    do {
                                                        cout << ">> ";
                                                        cin >> selectShip;
                                                    } while (selectShip < 0 || selectShip > 5);
                                                    system("cls");

                                                    bool done = false;
                                                    switch(selectShip){
                                                        case 1:{
                                                            do {
                                                                for(int i = 0; i < destroyerShipLength; i++){
                                                                    mapBattleShip[destroyerY][destroyerX + i] = 2;
                                                                }

                                                                cout << "== Destroyer Ship \033[31m**\033[0m ==" << endl << endl;

                                                                displayBoard();

                                                                cout << endl;

                                                                gerak = getch();

                                                                gerakKapal(gerak, destroyerX, destroyerY, destroyerShipLength, destroyer);

                                                                if (gerak == 'e'){
                                                                    done = true;
                                                                }

                                                            system("cls");
                                                            } while (!done);
                                                        break;
                                                        }
                                                        case 2:{
                                                            do {
                                                                for(int i = 0; i < submarineShipLength; i++){
                                                                    mapBattleShip[submarineY][submarineX + i] = 3;
                                                                }

                                                                cout << "== Submarine Ship \033[32m***\033[0m ==" << endl << endl;

                                                                displayBoard();

                                                                cout << endl;

                                                                gerak = getch();

                                                                gerakKapal(gerak, submarineX, submarineY, submarineShipLength, submarine);

                                                                if (gerak == 'e'){
                                                                    done = true;
                                                                }

                                                            system("cls");
                                                            } while (!done);
                                                        break;
                                                        }
                                                        case 3:{
                                                            do {
                                                                for(int i = 0; i < cruiserShipLength; i++){
                                                                    mapBattleShip[cruiserY][cruiserX + i] = 4;
                                                                }

                                                                cout << "== Cruiser Ship \033[33m***\033[0m ==" << endl << endl;

                                                                displayBoard();

                                                                cout << endl;

                                                                gerak = getch();

                                                                gerakKapal(gerak, cruiserX, cruiserY, cruiserShipLength, cruiser);

                                                                if (gerak == 'e'){
                                                                    done = true;
                                                                }

                                                            system("cls");
                                                            } while (!done);
                                                        break;
                                                        }
                                                        case 4:{
                                                            do {
                                                                for(int i = 0; i < battleshipShipLength; i++){
                                                                    mapBattleShip[battleshipY][battleshipX + i] = 5;
                                                                }

                                                                cout << "== Battle Ship \033[34m****\033[0m ==" << endl << endl;

                                                                displayBoard();

                                                                cout << endl;

                                                                gerak = getch();

                                                                gerakKapal(gerak, battleshipX, battleshipY, battleshipShipLength, battleship);

                                                                if (gerak == 'e'){
                                                                    done = true;
                                                                }

                                                            system("cls");
                                                            } while (!done);
                                                        break;
                                                        }
                                                        case 5:{
                                                            do {
                                                                for(int i = 0; i < carrierShipLength; i++){
                                                                    mapBattleShip[carrierY][carrierX + i] = 6;
                                                                }

                                                                cout << "== Carrier Ship \033[35m*****\033[0m ==" << endl << endl;

                                                                displayBoard();

                                                                cout << endl;

                                                                gerak = getch();

                                                                gerakKapal(gerak, carrierX, carrierY, carrierShipLength, carrier);

                                                                if (gerak == 'e'){
                                                                    done = true;
                                                                }

                                                            system("cls");
                                                            } while (!done);
                                                        break;
                                                        }
                                                    }
                                                } while (selectShip != 0);
                                            break;
                                            }
                                        }
                                } while (levelGame != 0);
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
