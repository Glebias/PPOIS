#pragma once
#include "IAccount.h"
#include <string>
#include "Transaction.h"
#include <vector>

using namespace std;

class Account : public IAccount {
public:
    string accountNumber;
    double balance;
    vector<Transaction> transactions;
    string owner;

    Account(string number, string ownerName);
    double deposit(double amount) override;
    bool withdraw(double amount) override;
    double getBalance() const override;
    string getAccountType() const override; 
    vector<Transaction> getTransactionHistory() const;
};