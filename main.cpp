#include "console_menu.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {

    SetConsoleCP(1251);      
    SetConsoleOutputCP(1251); 

    ConsoleMenu menu("Ãëàâíîå ìåíþ");

    menu.addItem("Ïðèâåòñòâèå", []() {
        cout << "\nÏðèâåò, ìèð!\n";
        });

    menu.addItem("Ââîä èìåíè", []() {
        string name;
        cout << "Ââåäèòå âàøå èìÿ: ";
        cin.ignore();
        getline(cin, name);
        cout << "Ïðèâåò, " << name << "!\n";
        });

    menu.addItem("Êàëüêóëÿòîð", []() {
        int a = getIntInput("Ââåäèòå ïåðâîå ÷èñëî: ", -1000, 1000);
        int b = getIntInput("Ââåäèòå âòîðîå ÷èñëî: ", -1000, 1000);
        cout << "Ñóììà: " << a + b << "\n";
        });

    menu.run();
    return 0;
}
