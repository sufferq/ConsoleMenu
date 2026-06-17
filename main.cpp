#include "console_menu.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ConsoleMenu menu("Главное меню");
    
    menu.addItem("Приветствие", []() {
        cout << "\nПривет, мир!\n";
    });
    
    menu.addItem("Ввод имени", []() {
        string name;
        cout << "Введите ваше имя: ";
        cin.ignore();
        getline(cin, name);
        cout << "Привет, " << name << "!\n";
    });
    
    menu.addItem("Калькулятор", []() {
        int a = getIntInput("Введите первое число: ", -1000, 1000);
        int b = getIntInput("Введите второе число: ", -1000, 1000);
        cout << "Сумма: " << a + b << "\n";
    });
    
    menu.run();
    return 0;
}
