#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>

class Login {
public:
    void loadUsers();
    void loadManagers();  // New method to load manager data
    bool userLogin();
    bool managerLogin();  // New method for manager login
    std::string username;
    std::unordered_map<std::string, double> userBalances;  // Stores user balances
    bool isManager = false;  // Flag to check if logged in as a manager
private:
    std::unordered_map<std::string, std::string> userCredentials;
    std::unordered_map<std::string, std::string> managerCredentials;  // Store manager credentials
};
