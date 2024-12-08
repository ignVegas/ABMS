#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include "../Accounts/user_acc.h"

#ifndef LOGIN_H
#define LOGIN_H

class Login {
public:

	UserAccount* currentUser = nullptr;  // Pointer to the current user account

    void loadUsers();
    void loadManagers();  // New method to load manager data
    bool userLogin();
    bool managerLogin();  // New method for manager login
    bool handleLogin(bool isManager);
    std::string username;
    std::unordered_map<std::string, double> userBalances;  // Stores user balances
    bool isManager = false;  // Flag to check if logged in as a manager
private:
    std::unordered_map<std::string, std::string> userCredentials;
    std::unordered_map<std::string, std::string> managerCredentials;  // Store manager credentials
};

#endif // LOGIN_H