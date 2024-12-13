#include "Customer.h"

Customer::Customer(string n, string e) : name(n), email(e) {}

void Customer::addAccount(shared_ptr<IAccount> account) {
    accounts.push_back(account);
}

