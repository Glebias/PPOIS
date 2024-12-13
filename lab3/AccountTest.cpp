#include "gtest/gtest.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "Transaction.h"

// Тестирование класса Account
TEST(AccountTest, DepositTest) {
    Account account("123456", "John Doe");
    
    double newBalance = account.deposit(100.0);
    EXPECT_DOUBLE_EQ(newBalance, 100.0);
    EXPECT_DOUBLE_EQ(account.getBalance(), 100.0);
}

TEST(AccountTest, WithdrawTest) {
    Account account("123456", "John Doe");
    account.deposit(200.0); // Пополнение счета

    bool success = account.withdraw(100.0);
    EXPECT_TRUE(success);
    EXPECT_DOUBLE_EQ(account.getBalance(), 100.0);
}

TEST(AccountTest, WithdrawInsufficientFundsTest) {
    Account account("123456", "John Doe");

    bool success = account.withdraw(50.0); // Попытка снять средства с пустого счета
    EXPECT_FALSE(success);
    EXPECT_DOUBLE_EQ(account.getBalance(), 0.0);
}

TEST(AccountTest, MultipleTransactionsTest) {
    Account account("123456", "John Doe");
    account.deposit(300.0);
    account.withdraw(100.0);

    EXPECT_DOUBLE_EQ(account.getBalance(), 200.0);
}

TEST(AccountTest, TransactionHistoryTest) {
    Account account("123456", "John Doe");
    account.deposit(150.0);
    account.withdraw(50.0);
    
    vector<Transaction> history = account.getTransactionHistory();
    
    EXPECT_EQ(history.size(), 2); // Должно быть 2 транзакции
    EXPECT_EQ(history[0].getDetails(), "Transaction ID: txn1, Amount: 150.000000, Date: 2023-11-01, Type: deposit");
    EXPECT_EQ(history[1].getDetails(), "Transaction ID: txn2, Amount: 50.000000, Date: 2023-11-01, Type: withdraw");
}