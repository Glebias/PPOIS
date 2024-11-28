#include <gtest/gtest.h>
#include "Person.h"
#include "Admin.h"
#include "Equipment.h"
#include "Feedback.h"
#include "Member.h"
#include "Membership.h"
#include "Payment.h"
#include "Session.h"
#include "Trainer.h"
#include "Workout.h"
#include "Event.h"
#include "Location.h"
#include "Schedule.h"
#include "FitnessClass.h"
#include "Goal.h"
#include "NutritionPlan.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    cout << "Running tests..." << std::endl;
    return RUN_ALL_TESTS();
}