#include <gtest/gtest.h>
#include "BankEmployee.h"

// Тестовый класс для BankEmployee
class BankEmployeeTest : public ::testing::Test {
protected:
    BankEmployee* employee;

    void SetUp() override {
        employee = new BankEmployee("E123", "Alice Johnson", 50000.0);
    }

    void TearDown() override {
        delete employee;
    }
};

// Тест на создание сотрудника и получение его данных
TEST_F(BankEmployeeTest, CreateEmployee) {
    EXPECT_EQ(employee->getEmployeeId(), "E123");
    EXPECT_EQ(employee->getName(), "Alice Johnson");
    EXPECT_DOUBLE_EQ(employee->getSalary(), 50000.0);
}

// Тест на изменение зарплаты
TEST_F(BankEmployeeTest, SetSalary) {
    employee->setSalary(60000.0);
    EXPECT_DOUBLE_EQ(employee->getSalary(), 60000.0); // Проверка новой зарплаты
}

// Тест на валидацию данных
TEST_F(BankEmployeeTest, ValidateData) {
    EXPECT_EQ(employee->getEmployeeId(), "E123");
    EXPECT_EQ(employee->getName(), "Alice Johnson");
    EXPECT_DOUBLE_EQ(employee->getSalary(), 50000.0);
}
