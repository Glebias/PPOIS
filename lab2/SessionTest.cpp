#include <gtest/gtest.h>
#include "Trainer.h"
#include "Session.h"

TEST(SessionTest, GetSessionDate) {
    Trainer trainer("John", "john@example.com", "Yoga");
    Session session("2023-11-01", &trainer);
    EXPECT_EQ(session.getSessionDate(), "2023-11-01");
}

TEST(SessionTest, GetTrainer) {
    Trainer trainer("John", "john@example.com", "Yoga");
    Session session("2023-11-01", &trainer);
    EXPECT_EQ(session.getTrainer()->GetName(), "John");
    EXPECT_EQ(session.getTrainer()->getEmail(), "john@example.com");
}

