#pragma once
#include "Account.h"
#include <string>

using namespace std;

class SavingsAccount : public Account {
public:
    SavingsAccount(string number, string ownerName);
    double deposit(double amount) override;
    bool withdraw(double amount) override;
    string getAccountType() const override;
};