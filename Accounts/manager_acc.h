#include "../Accounts/account.h"
#include "../Accounts/user_acc.h"
#include <vector>
#include <iostream>
#include <fstream>

class ManagerAccount : public Account {
public:
    ManagerAccount(std::string accNum, double bal) : Account(accNum, bal) {}

    void createAccount(std::vector<UserAccount>& accounts, std::string username, std::string password, std::string accNum, double bal) {
        // Create a UserAccount object and store it
        UserAccount newAccount(accNum, bal);  // Use the account number and balance
        accounts.emplace_back(newAccount);

        // Now, save username, password, and the account ID somewhere (e.g., in a file or map)
        // This assumes you have a way to store username, password, and accountID (like in the users.txt file)
        std::ofstream outFile("users.txt", std::ios::app);
        if (outFile) {
            outFile << username << " " << password << " " << accNum << " " << bal << std::endl;
            std::cout << "Account created successfully for user: " << username << std::endl;
        }
        else {
            std::cerr << "Error: Could not write to users.txt" << std::endl;
        }
    }

    // Delete an existing user account
    void deleteAccount(std::vector<UserAccount>& accounts, const std::string& accNum, const std::string& username) {
        // Remove account from vector based on account number
        accounts.erase(std::remove_if(accounts.begin(), accounts.end(),
            [&](UserAccount& acc) { return acc.getAccountNumber() == accNum; }), accounts.end());

        // Also delete the user's record from users.txt or any relevant storage (simplified for demonstration)
        std::ifstream inFile("users.txt");
        std::ofstream tempFile("temp.txt");
        std::string fileUsername, filePassword, fileAccountID;
        double fileBalance;

        if (inFile && tempFile) {
            while (inFile >> fileUsername >> filePassword >> fileAccountID >> fileBalance) {
                if (fileAccountID != accNum) {
                    tempFile << fileUsername << " " << filePassword << " " << fileAccountID << " " << fileBalance << std::endl;
                }
            }
            inFile.close();
            tempFile.close();

            // Remove the old file and rename the temp file to users.txt
            remove("users.txt");
            rename("temp.txt", "users.txt");

            std::cout << "Account deleted successfully for user: " << username << std::endl;
        }
        else {
            std::cerr << "Error: Could not access users.txt" << std::endl;
        }
    }

    void deposit(double amount) override {} // Managers typically don't deposit/withdraw directly
    bool withdraw(double amount) override { return false; }
    void printAccountSummary() const override {}
};
