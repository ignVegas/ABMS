#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <unordered_map>
#include <string>
#include "Login/Login.h"

Login login; // log obj

// Managers: [username, password]
std::unordered_map<std::string, std::string> managers;

// Users: [ID, balance]
std::unordered_map<std::string, double> userAccounts;         // [ID, balance]

void getConsoleSize(int& width, int& height) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
}

// center text in console
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

void displayUserBalance(const std::string& username) {
    system("cls");  // Clears the screen
    int consoleWidth, consoleHeight;
    getConsoleSize(consoleWidth, consoleHeight);

    std::cout << "Login successful! Welcome, " << username << "!" << std::endl;

    // Retrieve and display the user's balance
    if (userAccounts.find(username) != userAccounts.end()) {
        std::cout << "Your balance: $" << userAccounts[username] << std::endl;
    }
    else {
        std::cout << "No account balance found." << std::endl;
    }

	std::cout << "Would you like to continue? (Y/N)" << std::endl;
	char choice;
	std::cin >> choice;
	if (choice == 'Y' || choice == 'y') {

	}
    else {
        std::cout << "Exiting..." << std::endl;
    }
}


int main() {
	displayLoginMenu();
    int choice;
	std::cin >> choice;
    login.loadUsers();
	switch (choice) {
	case 1:
        while (!login.userLogin()) { }

		displayUserBalance(login.username);

		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
	return 0;
}