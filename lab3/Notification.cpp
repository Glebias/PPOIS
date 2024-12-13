#include "Notification.h"
#include <string>
#include "Customer.h"

using namespace std;


Notification::Notification(const string& msg, const Customer& cust)
    : message(msg), customer(cust) {}

string Notification::sendNotification() const {
    return "Notification to " + customer.name + ": " + message;
}