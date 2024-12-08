#include "account.h"

#ifndef USERACCOUNT_H
#define USERACCOUNT_H

class UserAccount : public Account {
private:
    std::vector<std::string> transactionHistory;

public:
    UserAccount(std::string accNum, double bal)
        : Account(accNum, bal) {}

    void deposit(double amount) override {
        balance += amount;
        transactionHistory.push_back("Deposited: $" + std::to_string(amount));
    }

    bool withdraw(double amount) override {
        if (amount > balance) {
            std::cout << "Insufficient funds." << std::endl;
            return false;
        }
        balance -= amount;
        transactionHistory.push_back("Withdrew: $" + std::to_string(amount));
        return true;
    }

    void printAccountSummary() const override {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
        std::cout << "Transaction History:" << std::endl;
        for (const auto& transaction : transactionHistory) {
            std::cout << transaction << std::endl;
        }
    }
    double getBalance() const {
        return balance;
    }

    std::string getAccountNumber() const {
        return accountNumber;
    }
};


#endif // USERACCOUNT_H