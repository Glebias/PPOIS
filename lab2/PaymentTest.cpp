#include <gtest/gtest.h>
#include "Membership.h"
#include "Member.h"
#include "Payment.h"

TEST(PaymentTest, GetDate) {
    Member member("Alice", "alice@example.com", 30);
    Payment payment("Monthly", 50.0, "2023-11-01", &member);
    EXPECT_EQ(payment.GetDate(), "2023-11-01");
}

TEST(PaymentTest, IsFeeCorrect_ValidFee) {
    Member member("Alice", "alice@example.com", 30);
    Payment payment("Monthly", 50.0, "2023-11-01", &member);
    EXPECT_TRUE(payment.IsFeeCorrect());
}

TEST(PaymentTest, IsFeeCorrect_InvalidFee) {
    Member member("Alice", "alice@example.com", 30);
    Payment payment("Monthly", 30.0, "2023-11-01", &member);
    EXPECT_FALSE(payment.IsFeeCorrect());
}

TEST(PaymentTest, GetMember) {
    Member member("Alice", "alice@example.com", 30);
    Payment payment("Monthly", 50.0, "2023-11-01", &member);
    EXPECT_EQ(payment.getMember()->getEmail(), "alice@example.com");
}