#include <gtest/gtest.h>
#include "Schedule.h"
#include "Workout.h"

TEST(ScheduleTest, AddWorkout) {
    Schedule schedule;
    Workout workout("Cardio", 30);
    schedule.addWorkout(workout);
    
    EXPECT_EQ(schedule.getWorkouts().size(), 1);
    EXPECT_EQ(schedule.getWorkouts()[0].getType(), "Cardio");
}

TEST(ScheduleTest, AddMultipleWorkouts) {
    Schedule schedule;
    Workout workout1("Cardio", 30);
    Workout workout2("Strength", 45);
    
    schedule.addWorkout(workout1);
    schedule.addWorkout(workout2);
    
    EXPECT_EQ(schedule.getWorkouts().size(), 2);
    EXPECT_EQ(schedule.getWorkouts()[0].getType(), "Cardio");
    EXPECT_EQ(schedule.getWorkouts()[1].getType(), "Strength");
}

