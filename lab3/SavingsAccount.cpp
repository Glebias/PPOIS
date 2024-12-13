#include "Account.h"
#include "SavingsAccount.h"
#include <string>
#include <iostream>

using namespace std;

SavingsAccount::SavingsAccount(string number, string ownerName)
    : Account(number, ownerName) {}

double SavingsAccount::deposit(double amount) {
    Account::deposit(amount);
    cout << "Deposited to Savings Account: " << amount << endl;
    return balance;
}

bool SavingsAccount::withdraw(double amount) {
    return Account::withdraw(amount);
}

string SavingsAccount::getAccountType() const {
    return "Savings Account";
}