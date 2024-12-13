#include <gtest/gtest.h>
#include "ATM.h"
#include "Account.h" // Предполагается, что у вас есть реализация IAccount

// Тестовый класс для ATM
class ATMTest : public ::testing::Test {
protected:
    shared_ptr<IAccount> account;
    ATM* atm;

    void SetUp() override {
        account = make_shared<Account>("123456", "John Doe");
        account->deposit(500.0); // Начальный баланс аккаунта
        atm = new ATM("Main Street", 1000.0); // Создание банкомата с наличными
    }

    void TearDown() override {
        delete atm;
    }
};

// Тест на снятие наличных
TEST_F(ATMTest, WithdrawCashSuccess) {
    double initialBalance = account->getBalance();
    atm->withdrawCash(account, 200.0);

    EXPECT_DOUBLE_EQ(account->getBalance(), initialBalance - 200.0); // Проверка нового баланса
}

// Тест на снятие наличных с недостатком средств на аккаунте
TEST_F(ATMTest, WithdrawCashInsufficientFunds) {
    atm->withdrawCash(account, 600.0); // Пытаемся снять больше, чем на счете

    EXPECT_DOUBLE_EQ(account->getBalance(), 500.0); // Баланс должен остаться прежним
}

// Тест на снятие наличных с недостатком наличных в банкомате
TEST_F(ATMTest, WithdrawCashATMOutOfCash) {
    atm->withdrawCash(account, 1100.0); // Пытаемся снять больше, чем в банкомате

    EXPECT_DOUBLE_EQ(account->getBalance(), 500.0); // Баланс должен остаться прежним

}

// Тест на проверку баланса
TEST_F(ATMTest, CheckBalance) {
    double balance = atm->checkBalance(account);
    EXPECT_DOUBLE_EQ(balance, 500.0); // Проверка текущего баланса
}
