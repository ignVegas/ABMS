#include <string>
#include "../Login/login.h"
#include "../Accounts/user_acc.h"

void getConsoleSize(int& width, int& height);
void printCentered(const std::string& text, int consoleWidth);
void displayLoginMenu();
void displayBalanceMenu(UserAccount* currentUser);