#include <string>
#include <vector>
#include "Account.h"
#include "Card.h"
#include <memory>


Card::Card(string number, string expDate, string cvvCode, shared_ptr<IAccount> acct, string type)
    : cardNumber(number), expirationDate(expDate), cvv(cvvCode), account(acct), cardType(type) {}

bool Card::validate() const {
    return !cardNumber.empty() && !expirationDate.empty();
}