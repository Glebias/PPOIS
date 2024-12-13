#pragma once
#include <string>
#include "Account.h"
#include <memory>

using namespace std;

class Payment {
public:
    string paymentId;
    double amount;
    shared_ptr<IAccount> fromAccount; 
    shared_ptr<IAccount> toAccount; 

    Payment(string id, double amt, shared_ptr<IAccount> from, shared_ptr<IAccount> to);
    string processPayment();
};