#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <unordered_map>
#include <string>
#include "Login/Login.h"
#include "UI/UIUtils.h"

// Managers: [username, password]
std::unordered_map<std::string, std::string> managers;

// Users: [ID, balance]
std::unordered_map<std::string, double> userAccounts;         // [ID, balance]


int main() {
	displayLoginMenu();
    int choice;
	std::cin >> choice;
	switch (choice) {
	case 1: // user login
		handleLogin(false);
		break;
	case 2: //user create account
		break;
	case 3: // manager login
		handleLogin(true);
		break;
	default: // exit
		break;
	}
	return 0;
}