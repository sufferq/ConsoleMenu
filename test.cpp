#include "console_menu.h"
#include <iostream>
#include <cassert>
#include <windows.h>

using namespace std;

void testMenuItem() {
    bool executed = false;
    MenuItem item("Тест", [&]() { executed = true; });
    assert(item.label == "Тест");
    item.action();
    assert(executed == true);
    cout << "testMenuItem: OK\n";
}

void testConsoleMenu() {
    ConsoleMenu menu("Тестовое меню");
    assert(menu.getItemCount() == 0);

    menu.addItem("Пункт 1", []() {});
    menu.addItem("Пункт 2", []() {});
    assert(menu.getItemCount() == 2);

    cout << "testConsoleMenu: OK\n";
}

void testHandleInput() {
    ConsoleMenu menu("Тест");
    bool flag1 = false, flag2 = false;

    menu.addItem("Пункт 1", [&]() { flag1 = true; });
    menu.addItem("Пункт 2", [&]() { flag2 = true; });

    menu.handleInput(1);
    assert(flag1 == true);

    menu.handleInput(2);
    assert(flag2 == true);

    cout << "testHandleInput: OK\n";
}

void testGetInputLine() {
    cout << "testGetInputLine: пропущен (требует ручного ввода)\n";
}

void runAllTests() {
    cout << "=== ЗАПУСК ТЕСТОВ ===\n";
    testMenuItem();
    testConsoleMenu();
    testHandleInput();
    testGetInputLine();
    cout << "=== ВСЕ ТЕСТЫ ПРОЙДЕНЫ ===\n";
}

int main() {

    SetConsoleCP(1251);     
    SetConsoleOutputCP(1251);

    runAllTests();
    return 0;
}