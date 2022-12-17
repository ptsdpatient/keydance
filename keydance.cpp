#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <string>
#include <map>
#include <future>
char input;
bool gameOver = false;
int score = 0;
using namespace std;

int randomgen() {
    int randval = 0;
    while (randval < 13) {
        randval = rand() % 20;
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
    //std::cout << "music over";
    return 0;
}

char keyInput(char key) {
    cin >> key;
    input = key;
    cout << input;
    //if (key == 'q') { gameOver = true; }
    if (gameOver) exit(3);
    keyInput('a');
}


int gameStart() {

    char z[21];
    char x[21];
    char c[21];
    char v[21];
    while (!gameOver) {


        for (int i = 0; i < 20; i++) {

            if (z[i] != '*') { z[i] = ' '; }

            if (x[i] != '*') { x[i] = ' '; }

            if (c[i] != '*') { c[i] = ' '; }

            if (v[i] != '*') { v[i] = ' '; }

        }

        if (randomgen() % 6 == 4) {
            z[randomgen()] = '*';
            x[randomgen()] = '*';
            c[randomgen()] = '*';
            v[randomgen()] = '*';
        }

        for (int i = 0; i < 20; i++) {
            z[i] = z[i + 1];
            x[i] = x[i + 1];
            c[i] = c[i + 1];
            v[i] = v[i + 1];
        }
        std::cout << "\n\n";

        char keyDisplayList[4] = { 'z','x','c','v' };
        for (char kd : keyDisplayList) std::cout << " [" << kd << "]";
        std::cout << "\t\t score: " << score << endl;
        for (int i = 0; i < 10; i++) std::cout << " [" << z[i] << "] [" << x[i] << "] [" << c[i] << "] [" << v[i] << "] " << endl;
        std::cout << "\n";
        Sleep(300);

        system("cls");
    }
    return 0;
}

int main() {
    musicPlayer();
    future<char> asyncFunction = async(keyInput, 'a');
    gameStart();
    return 0;
}
