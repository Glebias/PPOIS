#include <gtest/gtest.h>
#include "Location.h"

TEST(LocationTest, GetAddress) {
    Location location("123 Gym St");
    EXPECT_EQ(location.getAddress(), "123 Gym St");
}