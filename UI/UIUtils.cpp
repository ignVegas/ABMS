#include "UIUtils.h"
#include <iostream>
#include <Windows.h>
#include "../Login/login.h"

Login login; // log obj
std::string currentUsername;  // Variable to hold the username after login

void handleLogin(bool manager) {
	if (manager)
    {
		login.loadManagers();
		while (!login.managerLogin()) {}
	}
    else 
    {
        login.loadUsers();
        while (!login.userLogin()) {}
        displayBalanceMenu(login.username);
    }
}


void getConsoleSize(int& width, int& height) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
}

void printCentered(const std::string& text, int consoleWidth) {
    int padding = (consoleWidth - text.length()) / 2;
    if (padding > 0) {
        std::cout << std::string(padding, ' ');
    }
    std::cout << text << std::endl;
}

void displayLoginMenu() {
    int consoleWidth, consoleHeight;
    getConsoleSize(consoleWidth, consoleHeight);

    const int menuHeight = 7;
    int verticalPadding = (consoleHeight - menuHeight) / 2;

    for (int i = 0; i < verticalPadding; ++i) {
        std::cout << std::endl;
    }

    printCentered("=========================", consoleWidth);
    printCentered("       LOGIN MENU       ", consoleWidth);
    printCentered("=========================", consoleWidth);
    printCentered("1. User Login", consoleWidth);
    printCentered("2. Create Account", consoleWidth);
    printCentered("3. Manager Login", consoleWidth);
    printCentered("4. Exit", consoleWidth);
    printCentered("=========================", consoleWidth);
}


void displayBalanceMenu(const std::string& username) {
    system("cls");  // Clears the screen
    int consoleWidth, consoleHeight;
    getConsoleSize(consoleWidth, consoleHeight);

    const int menuHeight = 9;
    int verticalPadding = (consoleHeight - menuHeight) / 2;

    for (int i = 0; i < verticalPadding; ++i) {
        std::cout << std::endl;
    }

    // Display the header
    printCentered("=========================", consoleWidth);
    printCentered("          MANAGE         ", consoleWidth);
    printCentered("=========================", consoleWidth);

    // Display the balance and options
    printCentered("Balance: $" + std::to_string(login.userBalances[username]), consoleWidth);
    printCentered("=========================", consoleWidth);
    printCentered("1. Deposit", consoleWidth);
    printCentered("2. Withdraw", consoleWidth);
    printCentered("3. View Transactions", consoleWidth);
    printCentered("4. Exit", consoleWidth);
    printCentered("=========================", consoleWidth);
    int choice;
    std::cin >> choice;

}
