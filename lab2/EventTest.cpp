#include <gtest/gtest.h>
#include "Event.h"
#include "Location.h"

TEST(EventTest, GetName) {
    Location location("123 Gym St");
    Event event("Yoga Competition", "2023-12-01", &location);
    EXPECT_EQ(event.getName(), "Yoga Competition");
}

TEST(EventTest, GetDate) {
    Location location("123 Gym St");
    Event event("Yoga Competition", "2023-12-01", &location);
    EXPECT_EQ(event.getDate(), "2023-12-01");
}

TEST(EventTest, GetLocation) {
    Location location("123 Gym St");
    Event event("Yoga Competition", "2023-12-01", &location);
    EXPECT_EQ(event.getLocation()->getAddress(), "123 Gym St");
}

