#pragma once
#include <string>
#include <vector>
#include "Account.h"

using namespace std;

class CheckingAccount : public Account {
public:
    CheckingAccount(string number, string ownerName);
    double deposit(double amount) override;
    bool withdraw(double amount) override;
    string getAccountType() const override;
};