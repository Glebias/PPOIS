#include "Workout.h"
#include <gtest/gtest.h>

TEST(WorkoutTest, GetType) {
    Workout workout("Cardio", 120);
    EXPECT_EQ(workout.getType(), "Cardio");
}

TEST(WorkoutTest, GetDuration) {
    Workout workout("Cardio", 120);
    EXPECT_EQ(workout.getDuration(), 120);
}

TEST(WorkoutTest, DurationInHours) {
    Workout workout("Cardio", 120);
    EXPECT_DOUBLE_EQ(workout.durationInHours(), 2.0);
}