cmake_minimum_required(VERSION 3.10)
project(Lab1)

set(CMAKE_CXX_STANDARD 14)

set(GTEST_ROOT "/home/glebas/Desktop/Libraries/googletest")
set(CMAKE_PREFIX_PATH ${GTEST_ROOT})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")

add_executable(my_tests 
    Person.cpp    
    Admin.cpp AdminTest.cpp
    Equipment.cpp EquipmentTest.cpp
    Feedback.cpp FeedbackTest.cpp
    Member.cpp MemberTest.cpp
    Membership.cpp MembershipTest.cpp
    Payment.cpp PaymentTest.cpp
    Session.cpp SessionTest.cpp
    Trainer.cpp TrainerTest.cpp
    Workout.cpp WorkoutTest.cpp
    Event.cpp EventTest.cpp
    Location.cpp LocationTest.cpp
    Schedule.cpp ScheduleTest.cpp
    FitnessClass.cpp FitnessClassTest.cpp
    Goal.cpp GoalTest.cpp
    NutritionPlan.cpp NutritionPlanTest.cpp
    RunAllTests.cpp

)

target_link_libraries(my_tests ${GTEST_LIBRARIES} pthread)

enable_testing()

add_test(NAME MyTest COMMAND my_tests)

