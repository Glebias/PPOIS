#include "Member.h" 
#include <gtest/gtest.h>


TEST(MemberTest, GetName) {
    Member member("Alice", "alice@example.com", 30);
    EXPECT_EQ(member.GetName(), "Alice");
}


TEST(MemberTest, GetEmail) {
    Member member("Alice", "alice@example.com", 30);
    EXPECT_EQ(member.getEmail(), "alice@example.com");
}


TEST(MemberTest, GetAge) {
    Member member("Alice", "alice@example.com", 30);
    EXPECT_EQ(member.getAge(), 30);
}


TEST(MemberTest, IsAdult) {
    Member member("Alice", "alice@example.com", 30);
    EXPECT_TRUE(member.isAdult()); 
    Member member2("Bob", "bob@example.com", 17);
    EXPECT_FALSE(member2.isAdult()); // 
}
