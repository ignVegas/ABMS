#include <string>

void getConsoleSize(int& width, int& height);
void printCentered(const std::string& text, int consoleWidth);
void displayLoginMenu();
void displayBalanceMenu(const std::string& username);
void handleLogin(bool manager);