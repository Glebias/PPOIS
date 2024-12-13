#include <gtest/gtest.h>
#include "InterestRate.h"

// Тестовый класс для InterestRate
class InterestRateTest : public ::testing::Test {
protected:
    InterestRate* interestRate;

    void SetUp() override {
        // Создание объекта InterestRate с типом и ставкой
        interestRate = new InterestRate("Savings", 2.5);
    }

    void TearDown() override {
        delete interestRate; // Освобождение памяти
    }
};

// Тест на создание объекта InterestRate и получение текущей ставки
TEST_F(InterestRateTest, CreateInterestRate) {
    EXPECT_EQ(interestRate->getCurrentRate(), 2.5); // Проверка текущей ставки
}
