#include "Login.h"

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
    }
    inFile.close();
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
