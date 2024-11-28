#include "Trainer.h"
#include <gtest/gtest.h>

TEST(TrainerTest, GetName) {
    Trainer trainer("John", "john@example.com", "Yoga");
    EXPECT_EQ(trainer.GetName(), "John");
}

TEST(TrainerTest, GetEmail) {
    Trainer trainer("John", "john@example.com", "Yoga");
    EXPECT_EQ(trainer.getEmail(), "john@example.com");
}

TEST(TrainerTest, GetSpecialization) {
    Trainer trainer("John", "john@example.com", "Yoga");
    EXPECT_EQ(trainer.GetSpecialization(), "Yoga");
}

