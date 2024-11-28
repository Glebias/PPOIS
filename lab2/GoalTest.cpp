#include <gtest/gtest.h>
#include "Goal.h"

TEST(GoalTest, GetDescription) {
    Goal goal("Lose weight");
    EXPECT_EQ(goal.getDescription(), "Lose weight");
}