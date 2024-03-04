#include "function.cpp"
using namespace std;

int main() {
    ATM atm;

    // Create some accounts
    atm.addAccount(1234);
    atm.addAccount(5678);

    // Select account and perform operations
    atm.selectAccount(1234);
    atm.deposit(100);
    atm.withdraw(50);
    atm.viewBalance();

    atm.selectAccount(5678);
    atm.deposit(500);
    atm.viewBalance();
    atm.withdraw(1000);

    return 0;
}
