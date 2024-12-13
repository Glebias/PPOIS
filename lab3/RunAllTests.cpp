#include <gtest/gtest.h>
#include "Account.h"
#include "ATM.h"
#include "Bank.h"
#include "BankEmployee.h"
#include "Card.h"
#include "CheckingAccount.h"
#include "Customer.h"
#include "IAccount.h"
#include "InterestRate.h"
#include "Notification.h"
#include "Payment.h"
#include "SavingsAccount.h"
#include "Security.h"
#include "Transaction.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    cout << "Running tests..." << std::endl;
    return RUN_ALL_TESTS();
}