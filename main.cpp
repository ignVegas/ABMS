#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <unordered_map>
#include <string>
#include "Login/Login.h"
#include "UI/UIUtils.h"



int main() {
    Login login;
    login.loadUsers();
    std::unordered_map<std::string, UserAccount> userAccounts;
    bool loggedIn = false;
    while (!loggedIn) {
        displayLoginMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: // User Login
            loggedIn = login.userLogin();
            break;
        case 2: // Create Account
            break;
        case 3: // Manager Login
            loggedIn = login.managerLogin();
            break;
        case 4: // Exit
            std::cout << "Goodbye!" << std::endl;
            Sleep(1500);
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    if (login.currentUser) {
        displayBalanceMenu(login.currentUser);
        int action;
		std::cin >> action;

		switch (action) {
		case 1: // Deposit
			break;
		case 2: // Withdraw
			// Withdraw logic
			break;
		case 3: // view transactions
			break;
		case 4:
			exit(0);
			break;
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
		}
	}

    delete login.currentUser; // Clean up dynamically allocated memory
    return 0;
}