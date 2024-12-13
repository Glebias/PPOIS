#include <string>
#include <vector>
#include "Customer.h"
#include "Bank.h"


Bank::Bank(string n) : name(n) {}

void Bank::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

Customer* Bank::findCustomer(const string& name) {
    for (auto& customer : customers) {
        if (customer.name == name) {
            return &customer;
        }
    }
    return nullptr;
}