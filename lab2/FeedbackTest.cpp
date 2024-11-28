#include <gtest/gtest.h>
#include "Member.h"
#include "Feedback.h"

TEST(FeedbackTest, GetComment) {
    Member member("Alice", "alice@example.com", 30);
    Feedback feedback("Great service!", &member);
    EXPECT_EQ(feedback.getComment(), "Great service!");
}

TEST(FeedbackTest, GetMember) {
    Member member("Alice", "alice@example.com", 30);
    Feedback feedback("Great service!", &member);
    EXPECT_EQ(feedback.getMember()->getEmail(), "alice@example.com");
}

