#pragma once
#include <string>
#include <vector>
#include "Account.h"
#include "IAccount.h"
#include <memory>

class Customer {
public:
    string name;
    string email;
    vector<shared_ptr<IAccount>> accounts; 

    Customer(string n, string e);
    void addAccount(shared_ptr<IAccount> account);
    
};