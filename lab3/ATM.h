#pragma once
#include <string>
#include "Account.h"
#include <memory>

using namespace std;

class ATM {
public:
    string location;
    double availableCash;

    ATM(string loc, double cash);
    void withdrawCash(shared_ptr<IAccount> account, double amount);
    double checkBalance(const shared_ptr<IAccount>& account) const;
};