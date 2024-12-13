#include <gtest/gtest.h>
#include "CheckingAccount.h"

class CheckingAccountTest : public ::testing::Test {
protected:
    CheckingAccount *account;

    void SetUp() override {
        account = new CheckingAccount("123456", "John Doe");
    }

    void TearDown() override {
        delete account;
    }
};

// Тест на создание аккаунта
TEST_F(CheckingAccountTest, CreateAccount) {
    EXPECT_EQ(account->getAccountType(), "Checking Account");
}

// Тест на депозит
TEST_F(CheckingAccountTest, Deposit) {
    double initialBalance = account->getBalance();
    double depositAmount = 100.0;
    double newBalance = account->deposit(depositAmount);
    
    EXPECT_EQ(newBalance, initialBalance + depositAmount);
    EXPECT_GE(newBalance, depositAmount); // Проверяем, что баланс увеличился
}

// Тест на успешное снятие средств
TEST_F(CheckingAccountTest, WithdrawSuccess) {
    account->deposit(200.0); // Сначала сделаем депозит
    bool result = account->withdraw(150.0);
    
    EXPECT_TRUE(result); // Снятие должно быть успешным
    EXPECT_EQ(account->getBalance(), 50.0); // Проверяем новый баланс
}

// Тест на неудачное снятие средств (например, недостаточно средств)
TEST_F(CheckingAccountTest, WithdrawFailure) {
    account->deposit(100.0); // Сначала сделаем депозит
    bool result = account->withdraw(150.0);
    
    EXPECT_FALSE(result); // Снятие должно завершиться неудачей
    EXPECT_EQ(account->getBalance(), 100.0); // Баланс не должен измениться
}

// Тест на получение типа аккаунта
TEST_F(CheckingAccountTest, AccountType) {
    EXPECT_EQ(account->getAccountType(), "Checking Account");
}
