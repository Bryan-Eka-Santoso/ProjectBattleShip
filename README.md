# C++ Language

<p align="center">
<img src="assets_readme/img/cpp_logo.png"/>
</p>
<p align="center">
    <a href="https://github.com/federico-busato/Modern-CPP-Programming/releases" alt="Release">
        <img src="https://img.shields.io/github/v/release/federico-busato/Modern-CPP-Programming?style=for-the-badge"/>
    </a>
</p>

<p align="center">
    <a alt="Stars">
        <img src="https://img.shields.io/github/stars/federico-busato/Modern-CPP-Programming?style=for-the-badge"/>
    </a>
    <a href="https://github.com/federico-busato/Modern-CPP-Programming/network/members" alt="Forks">
        <img src="https://img.shields.io/github/forks/federico-busato/Modern-CPP-Programming?style=for-the-badge"/>
    </a>
</p>
<p align="center">
    <a href="https://github.com/federico-busato/Modern-CPP-Programming/commits/master" alt="Commits">
        <img src="https://badgen.net/github/commits/federico-busato/Modern-CPP-Programming?style=for-the-badge&scale=1.2"/>
    </a>
</p>
<p align="center">
    <a href="https://github.com/federico-busato/Modern-CPP-Programming-Material/issues" alt="Issues">
        <img src="https://badgen.net/github/closed-issues/federico-busato/Modern-CPP-Programming?style=for-the-badge&scale=1.2"/>
    </a>
</p>

# Penjelasan Game Battleship

<p align="center">
<img src="assets_readme/img/bluemap.png"/>
<img src="assets_readme/img/redmap.png"/>
</p>
Game ini memiliki lebar map permainan yaitu 7 x 9 dan memiliki 5 macam kapal dalam permainan yaitu :

* Berwarna Merah ( 1 x 2 ) : Destroyer Ship
* Berwarna Hijau ( 1 x 3 ) : Submarine Ship
* Berwarna Kuning ( 1 x 3 ) : Cruiser Ship
* Berwarna Biru ( 1 x 4 ) : Battle Ship
* Berwarna Ungu ( 1 x 5 ) : Carrier Ship

<p align="center">
<img src="assets_readme/img/ship.png"/>
</p>

Game ini juga memiliki menu leaderboard yang kami ambil berdasarkan poin, poin kami ambil saat player benar menebak kapal dari ai dan juga sebaliknya. Pada leaderboard kami mengambil selisih terbesar kemenangan pada poin player pada ai. Game ini juga memiliki history game yang dapat membantu untuk melihat riwayat permainan pada semua menu dalam permainan battleship.
<br>
Game ini memiliki 2 mode yaitu VS AI dan juga 2 player. Pada VS AI kami memiliki 4 macam difficulty yaitu easy, medium, hard, dan juga Gacor !!!. Pada 4 macam difficulty tersebut kami membedakan nya dengan memberikan perbedaan celah kepada penebakan ai kepada map player. Pada mode 2 player, user bisa bermain 1v1 dengan 1 orang lain.

<p align="center">
<img src="assets_readme/img/setupship.png"/>
</p>
Selanjutnya kami memberikan menu untuk meng setup 5 kapal pada map, game ini memiliki fitur randomize untuk me random semua posisi pada 5 kapal pada koordinat koordinat yang berbeda. Game ini juga memiliki fitur rotasi, jadi user bisa merotasi kapal menjadi vertikal maupun horizontal.
<br>
Pada saat permainan game kami memberikan cheat dengan memasukkan kode cheat yaitu 777 ( rahasia ) untuk melihat semua posisi kapal pada map ai maupun map player sendiri. Saat permainan game kami memberikan fitur yang dapat membantu kapal mana yang tersisa dan juga kapal mana yang belum di temukan dan juga jika koordinat semua kapal di temukan maka di map game ini maka kapal akan di munculkan.

# ARRAY mapBattleShip1
sebagai map player 1 dan juga map user saat melawan ai.

```c++
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
```

# ARRAY mapBattleShip2
sebagai map player 2 dalam permainan mode 2 player.

```c++
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
```

# ARRAY mapBattleShipAi
sebagai map ai untuk mode permainan vs ai.

```c++
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
```

# PROCEDURE welcomeText
untuk penggambaran animasi tulisan game saat game di mulai.

```c++
    int textMenu[15][36] = {
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 2},
        {2, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2},
        {2, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 2},
        {2, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2},
        {2, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 3, 0, 3, 0, 0, 3, 3, 3, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 3, 3, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 3, 0, 3, 0, 0, 3, 3, 3, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
    };

    cout << lightBlack << "\n# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #"                                    << defaultColor;
    cout << lightBlack << "\n#" << lightCyan << "                                                                     "                  << lightBlack << "#" << defaultColor; Sleep(100);
    cout << lightBlack << "\n#" << lightCyan << "                                   # #  ( )                          "                  << lightBlack << "#" << defaultColor; Sleep(100);
    cout << lightBlack << "\n#" << lightCyan << "                                ___#_#___|__                         "                  << lightBlack << "#" << defaultColor; Sleep(100);
    cout << lightBlack << "\n#" << lightCyan << "                                ___#_#___|__                         "                  << lightBlack << "#" << defaultColor; Sleep(100);
    cout << lightBlack << "\n#" << lightCyan << "                            _  |____________|  _                     "                  << lightBlack << "#" << defaultColor; Sleep(100);
    cout << lightBlack << "\n#" << lightCyan << "                     _=====| | |            | | |==== _              "                  << lightBlack << "#" << defaultColor; Sleep(100);
    cout << lightBlack << "\n#" << lightCyan << "               =====| |.---------------------------. | |====         "                  << lightBlack << "#" << defaultColor; Sleep(100);
    cout << lightBlack << "\n#" << lightCyan << " <---------------------'   .  .  .  .  .  .  .  .   '--------------/ "                  << lightBlack << "#" << defaultColor; Sleep(100);
    cout << lightBlack << "\n#" << lightCyan << "   " << char(92) << "                                                              /  " << lightBlack << "#" << defaultColor; Sleep(100);
    cout << lightBlack << "\n#" << lightCyan << "    " << char(92) << "____________________________________________________________/   " << lightBlack << "#" << defaultColor; Sleep(100);
    cout << endl;

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 36; j++){
            if (textMenu[i][j] == 1){
                cout << lightRed << char(254) << " " << defaultColor;
                Sleep(10);
            } else if (textMenu[i][j] == 2){
                cout << lightBlack << "# " << defaultColor;
            } else if (textMenu[i][j] == 3){
                cout << lightBlue << char(254) << " " << defaultColor;
                Sleep(10);
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
```

# PROCEDURE displayMenu
untuk memunculkan menu - menu yang ada pada game ini, digunakan untuk : menu awal, menu memilih difficulty, menu untuk memilih mode, dan juga untuk keterangan mode yang di pilih.

# PROCEDURE displayBoard
untuk memunculkan map dengan kapal sesuai dengan warna nya masing masing dan map ini digunakan saat mengsetup semua kapal.

# PROCEDURE displayBoardPlay
untuk memunculkan map yang memiliki 2 mode yaitu untuk memunculkan map mode cheat dan untuk memunculkan map dengan keterangan tebakan koordinat benar ataupun salah dan juga untuk memberikan penggunaan keterangan koordinat.

# PROCEDURE gerakKapal
untuk menggerakkan kapal saat setup pada map player. Pada procedure ini berisi code untuk menjalankan kapal menggunakan w/a/s/d dan juga r untuk rotasi pada kapal.

# PROCEDURE spawnShip
untuk memastikan kapal muncul saat awal setup dengan posisi horizontal atau vertical.

# FUNCTION availableSpot
untuk pengecekan sebelum meletakkan kapal. Jika pada spawn terdapat nilai dari kapal lain pada mapBattleShip, maka function akan mengembalikan false. Sebaliknya jika pada spawn hanya terdapat nilai 0, function akan mengembalikan true.

# PROCEDURE deployShip
untuk menu saat menggerakkan kapal sesuai dengan kapal yang user pilih dengan memanggil procedure displayBoard untuk memunculkan map nya.

# PROCEDURE placeOneShipRandomly
untuk memposisikan posisi yang di random pada 1 kapal.

# PROCEDURE placeAllShipsRandomly
untuk memposisikan posisi yang di random pada semua kapal dan juga pengecekan ketersediaan map agar kapal tidak bertabrakan.

# PROCEDURE deployAndOperateShip
untuk mengecek gerak keyboard saat mengsetup kapal yaitu saat menyimpan posisi kapal dan juga untuk merandom kapal.

# PROCEDURE risetMap
untuk mengosongkan map dan menghilangkan posisi semua kapal saat ingin mengsetup kapal lagi.

# PROCEDURE risetCoordinate 
untuk mengembalikan posisi spawn kapal pada posisi koordinat x1 dan y1.

# PROCEDURE ResetMapAndShips 
yaitu untuk menggabungkan kedua procedure di dalam 1 procedure untuk mempersingkat code dan juga penggunaan code berkala.

# FUNCTION validateCoodinateInput
untuk memvalidasi coordinate ascii yang di kirim oleh user ataupun ai saat menebak posisi kapal.

# FUNCTION processCoordinates
untuk mengubah ascii yang di kirim user dari a1 menjadi koordinat yang kami dapatkan yaitu x1 dan y1.

# PROCEDURE displayShipPlay
untuk memunculkan keterangan kapal pada permainan game, jika user ataupun ai berhasil menebak seluruh badan kapal maka pada procedure ini kapal akan di hilangankan dan menyisakan keterangan kapal yang belum di temukan.

# FUNCTION AttackForAI
untuk menghasilkan koordinat pada ai sesuai dengan difficulty nya masing - masing untuk menebak map pada player. 

# PROCEDURE PositioningShips
untuk menu pemilihan setup kapal dan juga untuk memastikan bahwa kapal benar - benar di setup sepenuhnya.

# STRUCT PlayerScore
untuk meng-group agar vector dibawah ini bisa jalan. 

```
vector<PlayerScore> easyLeaderboard;
vector<PlayerScore> mediumLeaderboard;
vector<PlayerScore> hardLeaderboard;
vector<PlayerScore> gacorLeaderboard;
vector<PlayerScore> versusHistory;
```

# PROCEDURE loadLeaderboard
untuk membuka file leaderboard AI dan Versus, serta sorting dari urutannya dan maksimal top 10.

# PROCEDURE saveLeaderboard
untuk mengsave hasil dengan format yang ditentukan.

# PROCEDURE initializeLeaderboards
untuk membuka file - file leaderboard.

# PROCEDURE getUsername
untuk meminta username pada player dan mengreturn username tersebut.

# PROCEDURE addToLeaderboard
untuk mendapatkan nama dan menyimpan nama,skor,skorAI,waktu,dll.

# PROCEDURE addToLeaderboard (2)
untuk mendapatkan nama dan menyimpan nama,skor,waktu,dll.

# PROCEDURE displayLeaderboard
untuk mendisplay leaderboard di console.

# PROCEDURE displayHistory
untuk mendisplay history AI di console.

# PROCEDURE displayHistoryVersus
untuk mendisplay history khusus versus di console.

# PROCEDURE attackPhase
untuk memproses giliran dalam menebak koordinat kapal, untuk memproses pengamilan x dan y, perubahan symbol koordinat pada map, memberikan text keterangan kapal tidak ada ataupun tersisa berapa koordinat lagi yang harus di tebak, dan pengecekan untuk invalid coordinates.

