#include <gtest/gtest.h>
#include "Security.h"

// Тестовый класс для Security
class SecurityTest : public ::testing::Test {
protected:
    Security* security;

    void SetUp() override {
        // Создаем объект Security с паролем
        security = new Security("securePassword");
    }

    void TearDown() override {
        delete security; // Освобождение памяти
    }
};

// Тест на проверку правильного пароля
TEST_F(SecurityTest, CheckCorrectPassword) {
    EXPECT_TRUE(security->checkPassword("securePassword")); // Проверка на правильный пароль
}

// Тест на проверку неправильного пароля
TEST_F(SecurityTest, CheckIncorrectPassword) {
    EXPECT_FALSE(security->checkPassword("wrongPassword")); // Проверка на неправильный пароль
}
