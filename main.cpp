#include <iostream>

using namespace std;

int main()
{
    int menu, menuPlayGame, levelGame;
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
                                    cout << "== Choose Level Game ==" << endl;
                                    cout << "1. Easy" << endl;
                                    cout << "2. Medium" << endl;
                                    cout << "3. Hard" << endl;
                                    cout << "0. Back" << endl;
                                    do {
                                        cout << ">> ";
                                        cin >> levelGame;
                                    } while (levelGame < 0 || levelGame > 3);
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
