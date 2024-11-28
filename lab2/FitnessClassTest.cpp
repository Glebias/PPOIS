#include "FitnessClass.h"
#include "Trainer.h"
#include <gtest/gtest.h>

TEST(FitnessClassTest, GetName) {
    Trainer trainer("John", "john@example.com", "Yoga");
    FitnessClass fitnessClass("Yoga Class", &trainer);
    EXPECT_EQ(fitnessClass.getName(), "Yoga Class");
}

TEST(FitnessClassTest, GetTrainerName) {
    Trainer trainer("John", "john@example.com", "Yoga");
    FitnessClass fitnessClass("Yoga Class", &trainer);
    EXPECT_EQ(fitnessClass.getTrainer()->GetName(), "John");
}

TEST(FitnessClassTest, GetTrainerEmail) {
    Trainer trainer("John", "john@example.com", "Yoga");
    FitnessClass fitnessClass("Yoga Class", &trainer);
    EXPECT_EQ(fitnessClass.getTrainer()->getEmail(), "john@example.com");
}

