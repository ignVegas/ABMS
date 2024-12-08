#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

class Account {
protected: // classes derived from Account can access these members
    std::string accountNumber;
    double balance;

public:
    Account(std::string accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual ~Account() {}

    virtual void deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void printAccountSummary() const = 0;

    double getBalance() const { return balance; }
    std::string getAccountNumber() const { return accountNumber; }
};

#endif // ACCOUNT_H