#include "IAccount.h"
#include "Transaction.h"
#include <string>

using namespace std;

Transaction::Transaction(string id, double amt, string dt, string t)
    : transactionId(id), amount(amt), date(dt), type(t) {}

string Transaction::getDetails() const {
    return "Transaction ID: " + transactionId + ", Amount: " + to_string(amount) + ", Date: " + date + ", Type: " + type;
}