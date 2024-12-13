#include <gtest/gtest.h>
#include "Card.h"
#include "Account.h" // Предполагается, что этот заголовок содержит определение класса IAccount

// Тестовый класс для Card
class CardTest : public ::testing::Test {
protected:
    // Указатель на аккаунт (предполагается, что у вас есть реализация IAccount)
    std::shared_ptr<IAccount> account;

    void SetUp() override {
        // Создайте или замокайте объект IAccount
        account = std::make_shared<Account>("123456", "John Doe"); // Пример, измените по необходимости
    }
};

// Тест на создание карты

TEST_F(CardTest, ValidateCard) {
    Card validCard("4111111111111111", "12/25", "123", account, "Visa");
    EXPECT_TRUE(validCard.validate()); // Карта должна быть валидной

    Card invalidCard("", "12/25", "123", account, "Visa");
    EXPECT_FALSE(invalidCard.validate()); // Карта должна быть невалидной

    Card anotherInvalidCard("4111111111111111", "", "123", account, "Visa");
    EXPECT_FALSE(anotherInvalidCard.validate()); // Карта должна быть невалидной
}

