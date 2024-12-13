#include <gtest/gtest.h>
#include "Payment.h"
#include "Account.h" // Предполагается, что у вас есть реализация IAccount

// Тестовый класс для Payment
class PaymentTest : public ::testing::Test {
protected:
    shared_ptr<IAccount> fromAccount;
    shared_ptr<IAccount> toAccount;
    Payment* payment;

    void SetUp() override {
        fromAccount = make_shared<Account>("123456", "Sender Account");
        toAccount = make_shared<Account>("654321", "Receiver Account");

        // Загружаем начальный баланс на отправителе
        fromAccount->deposit(500.0);
        payment = new Payment("P001", 200.0, fromAccount, toAccount);
    }

    void TearDown() override {
        delete payment; // Освобождение памяти
    }
};

// Тест на успешную обработку платежа
TEST_F(PaymentTest, ProcessPaymentSuccess) {
    string expectedMessage = "Processed payment of 200.000000 from " + fromAccount->getAccountType() + " to " + toAccount->getAccountType();
    EXPECT_EQ(payment->processPayment(), expectedMessage); // Проверка сообщения

    EXPECT_DOUBLE_EQ(fromAccount->getBalance(), 300.0); // Проверка нового баланса отправителя
    EXPECT_DOUBLE_EQ(toAccount->getBalance(), 200.0);   // Проверка нового баланса получателя
}

// Тест на обработку платежа с недостаточным балансом

