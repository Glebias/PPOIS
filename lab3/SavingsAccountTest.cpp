#include "gtest/gtest.h"
#include "SavingsAccount.h"
#include "Transaction.h"

// Тестирование класса SavingsAccount
TEST(SavingsAccountTest, DepositTest) {
    SavingsAccount account("123456", "John Doe");

    double newBalance = account.deposit(100.0);
    EXPECT_DOUBLE_EQ(newBalance, 100.0);
    EXPECT_DOUBLE_EQ(account.getBalance(), 100.0);
}

TEST(SavingsAccountTest, WithdrawTest) {
    SavingsAccount account("123456", "John Doe");
    account.deposit(200.0); // Пополнение счета

    bool success = account.withdraw(100.0);
    EXPECT_TRUE(success);
    EXPECT_DOUBLE_EQ(account.getBalance(), 100.0);
}

TEST(SavingsAccountTest, WithdrawInsufficientFundsTest) {
    SavingsAccount account("123456", "John Doe");

    bool success = account.withdraw(50.0); // Попытка снять средства с пустого счета
    EXPECT_FALSE(success);
    EXPECT_DOUBLE_EQ(account.getBalance(), 0.0);
}

TEST(SavingsAccountTest, GetAccountTypeTest) {
    SavingsAccount account("123456", "John Doe");
    
    EXPECT_EQ(account.getAccountType(), "Savings Account");
}

TEST(SavingsAccountTest, MultipleTransactionsTest) {
    SavingsAccount account("123456", "John Doe");
    account.deposit(300.0);
    account.withdraw(100.0);

    EXPECT_DOUBLE_EQ(account.getBalance(), 200.0);
}