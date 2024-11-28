#include <gtest/gtest.h>
#include "Membership.h"

TEST(MembershipTest, GetType) {
    Membership membership("Premium", 50.0);
    EXPECT_EQ(membership.getType(), "Premium");
}

TEST(MembershipTest, GetFee) {
    Membership membership("Basic", 25.0);
    EXPECT_DOUBLE_EQ(membership.getFee(), 25.0);
}