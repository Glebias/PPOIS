#include <string>
#include "Account.h"
#include "ATM.h"
#include <memory>
#include <iostream>

using namespace std;

ATM::ATM(string loc, double cash)
    : location(loc), availableCash(cash) {}

void ATM::withdrawCash(shared_ptr<IAccount> account, double amount) {
    if (amount <= availableCash && amount <= account->getBalance()) {
        account->withdraw(amount);
        availableCash -= amount;
        cout << "Withdrew " << amount << " from ATM at " << location << endl;
    } else {
        cout << "ATM out of cash or insufficient account balance." << endl;
    }
}

double ATM::checkBalance(const shared_ptr<IAccount>& account) const {
    return account->getBalance();
}