#include "Account.h"
#include <iostream>
#include <string>
#include "Transaction.h"
#include <vector>

using namespace std;

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

string Account::getAccountType() const {
    return "Generic Account"; // Реализация для базового класса
}

