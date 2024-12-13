#pragma once
#include <string>
#include <vector>
#include "Customer.h"


class Bank {
public:
    string name;
    vector<Customer> customers;

    Bank(string n);
    void addCustomer(const Customer& customer);
    Customer* findCustomer(const string& name);
};