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
    Account.cpp AccountTest.cpp   
    ATM.cpp ATMTest.cpp
    Bank.cpp BankTest.cpp
    BankEmployee.cpp BankEmployeeTest.cpp
    Card.cpp CardTest.cpp
    CheckingAccount.cpp CheckingAccountTest.cpp
    Customer.cpp CustomerTest.cpp
    InterestRate.cpp InterestRateTest.cpp
    Notification.cpp NotificationTest.cpp
    Payment.cpp PaymentTest.cpp
    SavingsAccount.cpp SavingsAccountTest.cpp
    Security.cpp SecurityTest.cpp
    Transaction.cpp TransactionTest.cpp
    RunAllTests.cpp

)

target_link_libraries(my_tests ${GTEST_LIBRARIES} pthread)

enable_testing()

add_test(NAME MyTest COMMAND my_tests)
