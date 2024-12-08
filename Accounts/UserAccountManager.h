#include "user_acc.h"

class UserAccountManager {
public:
    static void handleAccountActions(UserAccount& userAccount, int choice) {
        double amount;
        switch (choice) {
        case 1: // Deposit
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            if (amount > 0) {
                userAccount.deposit(amount);
                std::cout << "Deposited $" << amount << " successfully!" << std::endl;
            }
            else {
                std::cout << "Invalid deposit amount." << std::endl;
            }
            break;

        case 2: // Withdraw
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            if (!userAccount.withdraw(amount)) {
                std::cout << "Insufficient funds or invalid amount." << std::endl;
            }
            else {
                std::cout << "Withdrew $" << amount << " successfully!" << std::endl;
            }
            break;

        case 3: // View Transactions
            userAccount.printAccountSummary();
            break;

        default:
            break;
        }
    }
};