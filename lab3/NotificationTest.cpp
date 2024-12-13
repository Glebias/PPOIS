#include <gtest/gtest.h>
#include "Notification.h"
#include "Customer.h"

// Тестовый класс для Notification
class NotificationTest : public ::testing::Test {
protected:
    Customer* customer;
    Notification* notification;

    void SetUp() override {
        customer = new Customer("John Doe","uu"); // Создание клиента с именем
        notification = new Notification("Your account has been updated.", *customer);
    }

    void TearDown() override {
        delete notification; // Освобождение памяти
        delete customer;     // Освобождение памяти
    }
};

// Тест на создание уведомления и его отправку
TEST_F(NotificationTest, SendNotification) {
    string expectedMessage = "Notification to John Doe: Your account has been updated.";
    EXPECT_EQ(notification->sendNotification(), expectedMessage); // Проверка правильности отправленного уведомления
}
