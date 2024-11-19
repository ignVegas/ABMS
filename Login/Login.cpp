#include "Login.h"
#include <Windows.h>
void Login::loadUsers() {
    std::ifstream inFile("users.txt");
    if (!inFile) {
        std::cerr << "Error: Could not open users.txt" << std::endl;
        return;
    }

    std::string username, password, accountID;
    double balance;
    while (inFile >> username >> password >> accountID >> balance) {
        userCredentials[username] = password;
        userBalances[username] = balance;  // Store the balance for each user
    }
    inFile.close();
}

// Load manager credentials from file
void Login::loadManagers() {
    std::ifstream inFile("managers.txt");
    if (!inFile) {
        std::cerr << "Error: Could not open managers.txt" << std::endl;
        return;
    }

    std::string managerName, password;
    while (inFile >> managerName >> password) {
        managerCredentials[managerName] = password;
    }
    inFile.close();
}

bool Login::managerLogin() {
    std::string managerName, password;

    std::cout << "Enter manager username: ";
    std::cin >> managerName;
    std::cout << "Enter manager password: ";
    std::cin >> password;

    if (managerCredentials.find(managerName) == managerCredentials.end()) {
        std::cout << "Manager not found. Please try again." << std::endl;
        return false;
    }

    if (managerCredentials[managerName] != password) {
        std::cout << "Incorrect password. Please try again." << std::endl;
        return false;
    }

    this->username = managerName;
    this->isManager = true;  // Flag manager login status
    std::cout << "Manager login successful! Welcome, " << managerName << "!" << std::endl;
    return true;
}

bool Login::userLogin() {
    std::string username, password;

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (userCredentials.find(username) == userCredentials.end()) {
        std::cout << "Username not found. Please try again." << std::endl;
        return false;
    }

    if (userCredentials[username] != password) {
        std::cout << "Incorrect password. Please try again." << std::endl;
        return false;
    }

	Login::username = username;
    std::cout << "Login successful! Welcome, " << username << "!" << std::endl;
    return true;
}
