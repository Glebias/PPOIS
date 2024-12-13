#include "gtest/gtest.h"
#include "Transaction.h"

// Тестирование конструктора Transaction
TEST(TransactionTest, ConstructorAndGetDetails) {
    Transaction transaction("TX123", 100.50, "2024-12-07", "Deposit");

    EXPECT_EQ(transaction.getDetails(), "Transaction ID: TX123, Amount: 100.500000, Date: 2024-12-07, Type: Deposit");
}

// Тестирование метода getDetails
TEST(TransactionTest, GetDetails) {
    Transaction transaction("TX456", 250.75, "2024-12-08", "Withdrawal");

    EXPECT_EQ(transaction.getDetails(), "Transaction ID: TX456, Amount: 250.750000, Date: 2024-12-08, Type: Withdrawal");
}

// Тестирование с нулевой суммой
TEST(TransactionTest, ZeroAmount) {
    Transaction transaction("TX789", 0.0, "2024-12-09", "Transfer");

    EXPECT_EQ(transaction.getDetails(), "Transaction ID: TX789, Amount: 0.000000, Date: 2024-12-09, Type: Transfer");
}

// Тестирование с отрицательной суммой
TEST(TransactionTest, NegativeAmount) {
    Transaction transaction("TX999", -50.00, "2024-12-10", "Refund");

    EXPECT_EQ(transaction.getDetails(), "Transaction ID: TX999, Amount: -50.000000, Date: 2024-12-10, Type: Refund");
}