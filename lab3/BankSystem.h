
#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

// Интерфейс для счетов
class IAccount {
public:
    virtual double deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual double getBalance() const = 0;
    virtual string getAccountType() const = 0;
};

// Класс для представления транзакции
class Transaction {
public:
    string transactionId;
    double amount;
    string date;
    string type; 

    Transaction(string id, double amt, string dt, string t);
    string getDetails() const;
};

// Базовый класс для представления банковского счета
class Account : public IAccount {
public:
    string accountNumber;
    double balance;
    vector<Transaction> transactions;
    string owner;

    Account(string number, string ownerName);
    virtual double deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual double getBalance() const override;
    virtual string getAccountType() const = 0; 
    vector<Transaction> getTransactionHistory() const;
};

// Производный класс для сберегательного счета
class SavingsAccount : public Account {
public:
    SavingsAccount(string number, string ownerName);
    double deposit(double amount) override;
    bool withdraw(double amount) override;
    string getAccountType() const override;
};

// Производный класс для расчетного счета
class CheckingAccount : public Account {
public:
    CheckingAccount(string number, string ownerName);
    double deposit(double amount) override;
    bool withdraw(double amount) override;
    string getAccountType() const override;
};

// Класс для представления клиента банка
class Customer {
public:
    string name;
    string email;
    vector<shared_ptr<IAccount>> accounts; 

    Customer(string n, string e);
    void addAccount(shared_ptr<IAccount> account);
    shared_ptr<IAccount> findAccount(const string& accountNumber);
};

// Класс для представления банка
class Bank {
public:
    string name;
    vector<Customer> customers;

    Bank(string n);
    void addCustomer(const Customer& customer);
    Customer* findCustomer(const string& name);
};

// Класс для представления банковской карты
class Card {
public:
    string cardNumber;
    string expirationDate;
    string cvv;
    shared_ptr<IAccount> account; 
    string cardType; 

    Card(string number, string expDate, string cvvCode, shared_ptr<IAccount> acct, string type);
    bool validate() const;
};

// Класс для представления сотрудника банка
class BankEmployee {
public:
    string employeeId;
    string name;
    double salary;

    BankEmployee(string id, string n, double sal);
};

// Класс для представления банкомата
class ATM {
public:
    string location;
    double availableCash;

    ATM(string loc, double cash);
    void withdrawCash(shared_ptr<IAccount> account, double amount);
    double checkBalance(const shared_ptr<IAccount>& account) const;
};

// Класс для управления процентными ставками
class InterestRate {
public:
    string type; 
    double rate;

    InterestRate(string t, double r);
    double getCurrentRate() const;
};

// Класс для представления уведомлений
class Notification {
public:
    string message;
    Customer customer;

    Notification(const string& msg, const Customer& cust);
    string sendNotification() const;
};

// Класс для управления безопасностью
class Security {
public:
    string passwordHash;

    Security(const string& pass);
    bool checkPassword(const string& password) const;
};

// Класс для представления платежей
class Payment {
public:
    string paymentId;
    double amount;
    shared_ptr<IAccount> fromAccount; 
    shared_ptr<IAccount> toAccount; 

    Payment(string id, double amt, shared_ptr<IAccount> from, shared_ptr<IAccount> to);
    string processPayment();
};
