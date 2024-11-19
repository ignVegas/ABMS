#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>

class Login {
public:
    void loadUsers();
    bool userLogin();
    std::string username;
private:
    std::unordered_map<std::string, std::string> userCredentials; // Stores user credentials
};
