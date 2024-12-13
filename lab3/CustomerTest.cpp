#include "gtest/gtest.h"
#include "Customer.h"
#include "SavingsAccount.h" // Подключите ваш класс аккаунта
#include <memory>

using namespace std;

// Тестирование метода addAccount
TEST(CustomerTest, AddAccount) {
    // Создание клиента
    Customer customer("John Doe", "john.doe@example.com");
    
    // Создание аккаунта
    shared_ptr<IAccount> account = make_shared<SavingsAccount>("123456", "John Doe");

    // Добавление аккаунта
    customer.addAccount(account);

    // Проверка, что аккаунт добавлен
    EXPECT_EQ(customer.accounts.size(), 1);
}