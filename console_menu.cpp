#include "console_menu.h"
#include <iostream>
#include <limits>

using namespace std;

MenuItem::MenuItem(const string& lbl, function<void()> act)
    : label(lbl), action(act) {
}

ConsoleMenu::ConsoleMenu(const string& t) : title(t), isRunning(false) {}

void ConsoleMenu::addItem(const string& label, function<void()> action) {
    items.push_back(MenuItem(label, action));
}

void ConsoleMenu::show() {
    clearScreen();
    cout << "\n=== " << title << " ===\n\n";
    for (size_t i = 0; i < items.size(); i++) {
        cout << i + 1 << ". " << items[i].label << "\n";
    }
    cout << "0. Выход\n\n";
    cout << "Выберите пункт: ";
}

void ConsoleMenu::handleInput(int choice) {
    if (choice == 0) {
        isRunning = false;
        cout << "Выход из программы.\n";
        return;
    }

    if (choice > 0 && choice <= (int)items.size()) {
        items[choice - 1].action();
    }
    else {
        cout << "Неверный выбор! Попробуйте снова.\n";
    }
    waitForEnter();
}

void ConsoleMenu::run() {
    isRunning = true;
    int choice;

    while (isRunning) {
        show();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Введите число!\n";
            waitForEnter();
            continue;
        }

        handleInput(choice);
    }
}

int ConsoleMenu::getItemCount() const {
    return items.size();
}

void ConsoleMenu::clearScreen() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void ConsoleMenu::waitForEnter() const {
    cout << "\nНажмите Enter для продолжения...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

string getInputLine(const string& prompt) {
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}

int getIntInput(const string& prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < min || value > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите число от " << min << " до " << max << "\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}