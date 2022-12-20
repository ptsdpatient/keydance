#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <string>
#include <map>
#include <future>
const int gameSpeed = 300;
const int rows =20;
char key1 = 'z';
char key2 = 'x';
char key3 = 'c';
char key4 = 'v';
char input='z';
char symbol = '*';
bool gameOver = false;
int score = 0;
using namespace std;
int intro() {
    system("cls");
    cout << "\n\n\t Hi there, this is a cpp game where you press keys when the symbol comes closer \n" << "\t This project was made by tansihq\n";
    for (int i = 0; i < 120; i++) cout << '-';
    cout <<" \n\n\t";
    return 0;
}
int randomgen() {
    int randval = 0;
    while (randval < rows-7) {
        randval = rand() % rows;
    }
    return randval;
}

int musicPlayer() {
    int prefix;
    int i;
    map<int, string> musicList{ {0,"disorder"},{1,"metamorphosis"},{2,"milkyway"},{3,"mirai"},{4,"afterdark"} };//map for music player
    std::cout << "Which music do you wish to play";
    for (i = 0; i < 5; i++) {
        std::cout << "\n [" << i << "]" << musicList[i];
    }
    std::cout << endl;
    cin >> i;
    string musicString = to_string(i) + ".wav"; //join substrings
    wstring conv = wstring(musicString.begin(), musicString.end());//temporary wide string conv, later used for lpcwstr(long pointer constant wide string)
    LPCWSTR musicName = conv.c_str();//final datatype/string passed on to Playsound first parameter
    PlaySound(musicName, NULL, SND_ASYNC);

    return 0;
}



int gameStart() {

    char z[rows+1];
    char x[rows+1];
    char c[rows+1];
    char v[rows+1];
    while (!gameOver) {

        
        
        for (int i = 0; i < rows; i++) {

            if (z[i] != symbol) { z[i] = ' '; }

            if (x[i] != symbol) { x[i] = ' '; }

            if (c[i] != symbol) { c[i] = ' '; }

            if (v[i] != symbol) { v[i] = ' '; }

        }

        if (randomgen() % 6 == 4) {
            z[randomgen()] = symbol;
            x[randomgen()] = symbol;
            c[randomgen()] = symbol;
            v[randomgen()] = symbol;
        }

        for (int i = 0; i < rows; i++) {
            z[i] = z[i + 1];
            x[i] = x[i + 1];
            c[i] = c[i + 1];
            v[i] = v[i + 1];
        }
        std::cout << "\n\n\n";
        if (_kbhit()) {
            input = _getch(); if ((z[0] == symbol && input == key1) || (x[0] == symbol && input == key2) || (c[0] == symbol && input == key3) || (v[0] == symbol && input == key4)) { score += 100; }
        }
        else { input = ' '; }
        char keyDisplayList[4] = { key1, key2, key3, key4 };
        cout << "\t\t";
        for (char kd : keyDisplayList) std::cout << " [" << kd << "]";
        std::cout << "\t\t score: " << score << "\t input: " << input<< endl;
        for (int i = 0; i < rows-10; i++) std::cout << "\t\t [" << z[i] << "] [" << x[i] << "] [" << c[i] << "] [" << v[i] << "] " << endl;
        std::cout << "\n";
        
        
        
        Sleep(gameSpeed);

       system("cls");
    }
    return 0;
}

int main() {
    intro();
    musicPlayer();
    gameStart();
    return 0;
}
