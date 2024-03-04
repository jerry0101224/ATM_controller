#include <iostream>
#include <unordered_map>

class Account {
private:
    int balance;

public:
    Account() : balance(0) {}

    int getBalance() const {
        return balance;
    }

    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited $" << amount << " successfully.\n";
        } else {
            std::cout << "Invalid deposit amount.\n";
        }
    }

    bool withdraw(int amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << " successfully.\n";
            return true;
        } else {
            std::cout << "Insufficient funds or invalid amount.\n";
            return false;
        }
    }
};

class ATM {
private:
    std::unordered_map<int, Account> accounts;
    Account* currentAccount;

public:
    void selectAccount(int accountNumber) {
        auto it = accounts.find(accountNumber);
        if (it != accounts.end()) {
            currentAccount = &it->second;
            std::cout << "Account " << accountNumber << " selected.\n";
        } else {
            std::cout << "Account not found.\n";
            currentAccount = nullptr;
        }
    }

    void viewBalance() {
        if (currentAccount != nullptr) {
            std::cout << "Current balance: $" << currentAccount->getBalance() << "\n";
        } else {
            std::cout << "No account selected.\n";
        }
    }

    void deposit(int amount) {
        if (currentAccount != nullptr) {
            currentAccount->deposit(amount);
        } else {
            std::cout << "No account selected.\n";
        }
    }

    void withdraw(int amount) {
        if (currentAccount != nullptr) {
            currentAccount->withdraw(amount);
        } else {
            std::cout << "No account selected.\n";
        }
    }

    void addAccount(int accountNumber) {
        accounts.emplace(accountNumber, Account());
        std::cout << "Account " << accountNumber << " created.\n";
    }
};


