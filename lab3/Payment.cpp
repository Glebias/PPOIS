#include <string>
#include "Account.h"
#include "Payment.h"
#include <memory>

Payment::Payment(string id, double amt, shared_ptr<IAccount> from, shared_ptr<IAccount> to)
    : paymentId(id), amount(amt), fromAccount(from), toAccount(to) {}

string Payment::processPayment() {
    fromAccount->withdraw(amount);
    toAccount->deposit(amount);
    return "Processed payment of " + to_string(amount) + " from " + fromAccount->getAccountType() + " to " + toAccount->getAccountType();
}