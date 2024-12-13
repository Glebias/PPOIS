#pragma once
#include <string>

class IAccount {
public:
    virtual double deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual double getBalance() const = 0;
    virtual std::string getAccountType() const = 0;
};