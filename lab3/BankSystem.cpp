#include "BankSystem.h"

Transaction::Transaction(string id, double amt, string dt, string t)
    : transactionId(id), amount(amt), date(dt), type(t) {}

string Transaction::getDetails() const {
    return "Transaction ID: " + transactionId + ", Amount: " + to_string(amount) + ", Date: " + date + ", Type: " + type;
}

Account::Account(string number, string ownerName)
    : accountNumber(number), owner(ownerName), balance(0.0) {}

double Account::deposit(double amount) {
    balance += amount;
    transactions.push_back(Transaction("txn" + to_string(transactions.size() + 1), amount, "2023-11-01", "deposit"));
    return balance;
}

bool Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        transactions.push_back(Transaction("txn" + to_string(transactions.size() + 1), amount, "2023-11-01", "withdraw"));
        return true;
    } else {
        cout << "Insufficient funds in " << owner << "'s account." << endl;
        return false;
    }
}

double Account::getBalance() const {
    return balance;
}

vector<Transaction> Account::getTransactionHistory() const {
    return transactions;
}

SavingsAccount::SavingsAccount(string number, string ownerName)
    : Account(number, ownerName) {}

double SavingsAccount::deposit(double amount) {
    Account::deposit(amount);
    cout << "Deposited to Savings Account: " << amount << endl;
    return balance;
}

bool SavingsAccount::withdraw(double amount) {
    return Account::withdraw(amount);
}

string SavingsAccount::getAccountType() const {
    return "Savings Account";
}

CheckingAccount::CheckingAccount(string number, string ownerName)
    : Account(number, ownerName) {}

double CheckingAccount::deposit(double amount) {
    Account::deposit(amount);
    cout << "Deposited to Checking Account: " << amount << endl;
    return balance;
}

bool CheckingAccount::withdraw(double amount) {
    return Account::withdraw(amount);
}

string CheckingAccount::getAccountType() const {
    return "Checking Account";
}

Customer::Customer(string n, string e) : name(n), email(e) {}

void Customer::addAccount(shared_ptr<IAccount> account) {
    accounts.push_back(account);
}

shared_ptr<IAccount> Customer::findAccount(const string& accountNumber) {
    for (const auto& account : accounts) {
        if (dynamic_cast<Account*>(account.get())->accountNumber == accountNumber) {
            return account;
        }
    }
    return nullptr;
}

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

Card::Card(string number, string expDate, string cvvCode, shared_ptr<IAccount> acct, string type)
    : cardNumber(number), expirationDate(expDate), cvv(cvvCode), account(acct), cardType(type) {}

bool Card::validate() const {
    return !cardNumber.empty() && !expirationDate.empty();
}

BankEmployee::BankEmployee(string id, string n, double sal)
    : employeeId(id), name(n), salary(sal) {}

ATM::ATM(string loc, double cash)
    : location(loc), availableCash(cash) {}

void ATM::withdrawCash(shared_ptr<IAccount> account, double amount) {
    if (amount <= availableCash && amount <= account->getBalance()) {
        account->withdraw(amount);
        availableCash -= amount;
        cout << "Withdrew " << amount << " from ATM at " << location << endl;
    } else {
        cout << "ATM out of cash or insufficient account balance." << endl;
    }
}

double ATM::checkBalance(const shared_ptr<IAccount>& account) const {
    return account->getBalance();
}

InterestRate::InterestRate(string t, double r) : type(t), rate(r) {}

double InterestRate::getCurrentRate() const {
    return rate;
}

Notification::Notification(const string& msg, const Customer& cust)
    : message(msg), customer(cust) {}

string Notification::sendNotification() const {
    return "Notification to " + customer.name + ": " + message;
}

Security::Security(const string& pass) : passwordHash(pass) {}

bool Security::checkPassword(const string& password) const {
    return passwordHash == password;
}

Payment::Payment(string id, double amt, shared_ptr<IAccount> from, shared_ptr<IAccount> to)
    : paymentId(id), amount(amt), fromAccount(from), toAccount(to) {}

string Payment::processPayment() {
    fromAccount->withdraw(amount);
    toAccount->deposit(amount);
    return "Processed payment of " + to_string(amount) + " from " + fromAccount->getAccountType() + " to " + toAccount->getAccountType();
}
