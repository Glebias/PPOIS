#include <string>
#include <vector>
#include "Account.h"
#include "CheckingAccount.h"
#include <iostream>


CheckingAccount::CheckingAccount(string number, string ownerName)
    : Account(number, ownerName) {}

double CheckingAccount::deposit(double amount) {
    Account::deposit(amount);
    cout << "Deposited to Checking Account: " << amount << endl;
    return balance;
}

bool CheckingAccount::withdraw(double amount) {
    return Account::withdraw(amount);
}

string CheckingAccount::getAccountType() const {
    return "Checking Account";
}