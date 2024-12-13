#pragma once
#include "IAccount.h"
#include <string>

using namespace std;

class Transaction {
public:
    string transactionId;
    double amount;
    string date;
    string type; 

    Transaction(string id, double amt, string dt, string t);
    string getDetails() const;
};