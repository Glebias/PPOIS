#include "BankSystem.h"
#include <gtest/gtest.h>

// Тесты для класса Transaction
TEST(TransactionTest, GetDetails) {
    Transaction txn("txn1", 100.0, "2023-11-01", "deposit");
    EXPECT_EQ(txn.getDetails(), "Transaction ID: txn1, Amount: 100.000000, Date: 2023-11-01, Type: deposit");
}

// Тесты для класса Account
TEST(AccountTest, Deposit) {
    SavingsAccount account("123456", "Alice");
    EXPECT_DOUBLE_EQ(account.deposit(1000), 1000);
}

TEST(AccountTest, Withdraw) {
    SavingsAccount account("123456", "Alice");
    account.deposit(1000);
    EXPECT_TRUE(account.withdraw(200));
    EXPECT_DOUBLE_EQ(account.getBalance(), 800);
    EXPECT_FALSE(account.withdraw(1000)); 
}

// Тесты для класса Customer
TEST(CustomerTest, AddAndFindAccount) {
    Customer customer("Alice", "alice@example.com");
    shared_ptr<IAccount> account = make_shared<SavingsAccount>("123456", "Alice");
    customer.addAccount(account);
    EXPECT_EQ(customer.findAccount("123456")->getAccountType(), "Savings Account");
}

// Тесты для класса Bank
TEST(BankTest, AddAndFindCustomer) {
    Bank bank("MyBank");
    Customer customer("Alice", "alice@example.com");
    bank.addCustomer(customer);
    EXPECT_EQ(bank.findCustomer("Alice")->name, "Alice");
}

// Тесты для класса Card
TEST(CardTest, Validate) {
    shared_ptr<IAccount> account = make_shared<SavingsAccount>("123456", "Alice");
    Card card("1234567890123456", "12/25", "123", account, "debit");
    EXPECT_TRUE(card.validate());
}

// Тесты для класса ATM
TEST(ATMTest, WithdrawCash) {
    shared_ptr<IAccount> account = make_shared<SavingsAccount>("123456", "Alice");
    account->deposit(1000);
    ATM atm("Main Street", 500);
    atm.withdrawCash(account, 200);
    EXPECT_DOUBLE_EQ(account->getBalance(), 800);
}

TEST(ATMTest, WithdrawInsufficientCash) {
    shared_ptr<IAccount> account = make_shared<SavingsAccount>("123456", "Alice");
    account->deposit(200);
    ATM atm("Main Street", 100);
    atm.withdrawCash(account, 300); // Должно провалиться
    EXPECT_DOUBLE_EQ(account->getBalance(), 200);
}

// Тесты для класса Payment
TEST(PaymentTest, ProcessPayment) {
    shared_ptr<IAccount> fromAccount = make_shared<SavingsAccount>("123456", "Alice");
    shared_ptr<IAccount> toAccount = make_shared<CheckingAccount>("123457", "Bob");
    fromAccount->deposit(500);
    Payment payment("payment1", 200, fromAccount, toAccount);
    payment.processPayment();
    EXPECT_DOUBLE_EQ(fromAccount->getBalance(), 300);
    EXPECT_DOUBLE_EQ(toAccount->getBalance(), 200);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}