#include <gtest/gtest.h>
#include "Bank.h"
#include "Customer.h"

// Тестовый класс для Bank
class BankTest : public ::testing::Test {
protected:
    Bank* bank;

    void SetUp() override {
        bank = new Bank("My Bank");
    }

    void TearDown() override {
        delete bank;
    }
};

// Тест на добавление клиента
TEST_F(BankTest, AddCustomer) {
    Customer customer("John Doe","gg");
    bank->addCustomer(customer);

    Customer* foundCustomer = bank->findCustomer("John Doe");
    EXPECT_NE(foundCustomer, nullptr); // Клиент должен быть найден
    EXPECT_EQ(foundCustomer->name, "John Doe"); // Проверка имени клиента
}

// Тест на поиск несуществующего клиента
TEST_F(BankTest, FindNonExistentCustomer) {
    Customer* foundCustomer = bank->findCustomer("Non Existent");
    EXPECT_EQ(foundCustomer, nullptr); // Клиент не должен быть найден
}

// Тест на добавление нескольких клиентов
TEST_F(BankTest, AddMultipleCustomers) {
    Customer customer1("Alice","gj");
    Customer customer2("Bob","kl");
    bank->addCustomer(customer1);
    bank->addCustomer(customer2);

    EXPECT_NE(bank->findCustomer("Alice"), nullptr); // Проверка первого клиента
    EXPECT_NE(bank->findCustomer("Bob"), nullptr); // Проверка второго клиента
}
