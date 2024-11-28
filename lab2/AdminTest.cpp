#include "Admin.h"
#include <gtest/gtest.h>

TEST(AdminTest, GetName) {
    Admin admin("Admin", "admin@example.com", 40);
    EXPECT_EQ(admin.GetName(), "Admin");
}

TEST(AdminTest, GetWorkTime) {
    Admin admin("Admin", "admin@example.com", 40);
    EXPECT_EQ(admin.getWorkTime(), 40);
}

TEST(AdminTest, GetEmail) {
    Admin admin("Admin", "admin@example.com");
    EXPECT_EQ(admin.getEmail(), "admin@example.com");
}
