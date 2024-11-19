#include "../Accounts/account.h"
#include "../Accounts/user_acc.h"
#include <vector>
#include <iostream>

class ManagerAccount : public Account {
public:
    ManagerAccount(std::string accNum, double bal) : Account(accNum, bal) {}

    void createAccount(std::vector<UserAccount>& accounts, std::string accNum, double bal) {
        accounts.emplace_back(accNum, bal);
        std::cout << "Account created successfully." << std::endl;
    }

    void deleteAccount(std::vector<UserAccount>& accounts, const std::string& accNum) {
        accounts.erase(std::remove_if(accounts.begin(), accounts.end(),
            [&](UserAccount& acc) { return acc.getAccountNumber() == accNum; }), accounts.end());
        std::cout << "Account deleted successfully." << std::endl;
    }

    void deposit(double amount) override {} // Managers typically don't deposit/withdraw directly
    bool withdraw(double amount) override { return false; }
    void printAccountSummary() const override {}
};
