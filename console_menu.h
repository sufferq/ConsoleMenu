#ifndef CONSOLE_MENU_H
#define CONSOLE_MENU_H

#include <string>
#include <vector>
#include <functional>

class MenuItem {
public:
    std::string label;
    std::function<void()> action;

    MenuItem(const std::string& lbl, std::function<void()> act);
};

class ConsoleMenu {
private:
    std::string title;
    std::vector<MenuItem> items;
    bool isRunning;

public:
    ConsoleMenu(const std::string& t);

    void addItem(const std::string& label, std::function<void()> action);
    void show();
    void handleInput(int choice);
    void run();
    int getItemCount() const;
    void clearScreen() const;
    void waitForEnter() const;
};

std::string getInputLine(const std::string& prompt);
int getIntInput(const std::string& prompt, int min, int max);

#endif