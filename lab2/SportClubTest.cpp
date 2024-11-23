#include <gtest/gtest.h>
#include "SportClub.h"

// Тесты для класса Member
TEST(MemberTest, DisplayInfo) {
    Member member("Alice", "alice@example.com", 30);
    EXPECT_EQ(member.GetName(), "Alice");
    EXPECT_EQ(member.getEmail(), "alice@example.com");
    EXPECT_EQ(member.getAge(), 30);
    EXPECT_TRUE(member.isAdult());
}

// Тесты для класса Trainer
TEST(TrainerTest, DisplayInfo) {
    Trainer trainer("John", "john@example.com", "Yoga");
    EXPECT_EQ(trainer.GetName(), "John");
    EXPECT_EQ(trainer.getEmail(), "john@example.com");
    EXPECT_EQ(trainer.GetSpecialization(), "Yoga");
}

// Тесты для класса Admin
TEST(AdminTest, DisplayInfo) {
    Admin admin("Admin", "admin@example.com");
    EXPECT_EQ(admin.GetName(), "Admin");
    EXPECT_EQ(admin.getEmail(), "admin@example.com");
}

// Тесты для класса Workout
TEST(WorkoutTest, DurationInHours) {
    Workout workout("Cardio", 120);
    EXPECT_EQ(workout.getType(), "Cardio");
    EXPECT_EQ(workout.getDuration(), 120);
    EXPECT_DOUBLE_EQ(workout.durationInHours(), 2.0);
}

// Тесты для класса FitnessClass
TEST(FitnessClassTest, GetName) {
    Trainer trainer("John", "john@example.com", "Yoga");
    FitnessClass fitnessClass("Yoga Class", &trainer);
    EXPECT_EQ(fitnessClass.getName(), "Yoga Class");
    EXPECT_EQ(fitnessClass.getTrainer()->GetName(), "John");
}

// Тесты для класса Payment
TEST(PaymentTest, IsFeeCorrect) {
    Member member("Alice", "alice@example.com", 30);
    Payment payment("Monthly", 50.0, "2023-11-01", &member);
    EXPECT_TRUE(payment.IsFeeCorrect());
}

// Тесты для класса Location
TEST(LocationTest, GetAddress) {
    Location location("123 Gym St");
    EXPECT_EQ(location.getAddress(), "123 Gym St");
}

// Тесты для класса Event
TEST(EventTest, GetName) {
    Location location("123 Gym St");
    Event event("Yoga Competition", "2023-12-01", &location);
    EXPECT_EQ(event.getName(), "Yoga Competition");
    EXPECT_EQ(event.getDate(), "2023-12-01");
}

// Тесты для класса NutritionPlan
TEST(NutritionPlanTest, GetDetails) {
    NutritionPlan plan("High protein diet");
    EXPECT_EQ(plan.getDetails(), "High protein diet");
}

// Тесты для класса Schedule
TEST(ScheduleTest, AddWorkout) {
    Schedule schedule;
    Workout workout("Cardio", 30);
    schedule.addWorkout(workout);
    EXPECT_EQ(schedule.getWorkouts().size(), 1);
    EXPECT_EQ(schedule.getWorkouts()[0].getType(), "Cardio");
}

// Тесты для класса Goal
TEST(GoalTest, GetDescription) {
    Goal goal("Lose weight");
    EXPECT_EQ(goal.getDescription(), "Lose weight");
}

// Тесты для класса Feedback
TEST(FeedbackTest, GetComment) {
    Member member("Alice", "alice@example.com", 30);
    Feedback feedback("Great service!", &member);
    EXPECT_EQ(feedback.getComment(), "Great service!");
}

// Тесты для класса Session
TEST(SessionTest, GetSessionDate) {
    Trainer trainer("John", "john@example.com", "Yoga");
    Session session("2023-11-01", &trainer);
    EXPECT_EQ(session.getSessionDate(), "2023-11-01");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    cout << "Running tests..." << std::endl;
    return RUN_ALL_TESTS();
}