#pragma once
#include <string>
#include "Customer.h"

using namespace std;

class Notification {
public:
    string message;
    Customer customer;

    Notification(const string& msg, const Customer& cust);
    string sendNotification() const;
};
