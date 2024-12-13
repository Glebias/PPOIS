#pragma once
#include <string>
#include <vector>
#include "Account.h"
#include <memory>

class Card {
public:
    string cardNumber;
    string expirationDate;
    string cvv;
    shared_ptr<IAccount> account; 
    string cardType; 

    Card(string number, string expDate, string cvvCode, shared_ptr<IAccount> acct, string type);
    bool validate() const;
};