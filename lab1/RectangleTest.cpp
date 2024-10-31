#include <gtest/gtest.h>
#include "Rectangle.h"


TEST(RectangleTest, Move) {
    Rectangle rect = Rectangle(1, 2, 3, 4);
   
    EXPECT_EQ(rect.move(2, 2), Rectangle(3, 4, 5, 6));
}

TEST(RectangleTest, Resize) {
    Rectangle rect = Rectangle(1, 2, 3, 4);
    EXPECT_EQ(rect.resize(8, 6), Rectangle(1, 2, 9, 8));
}

TEST(RectangleTest, Increment) {
    Rectangle rect = Rectangle(1, 2, 3, 4);
    EXPECT_EQ(++rect, Rectangle(1, 2, 4, 5));
    EXPECT_EQ(rect++, Rectangle(1, 2, 4, 5));
}

TEST(RectangleTest, Decrement) {
    Rectangle rect = Rectangle(1, 2, 3, 4);
    EXPECT_EQ(--rect, Rectangle(1, 2, 2, 3));
    EXPECT_EQ(rect--, Rectangle(1, 2, 2, 3));
}

TEST(RectangleTest, Addition) {
    Rectangle rect = Rectangle(1, 2, 3, 4);
    Rectangle rect1 = Rectangle(5, 6, 8, 9);
    EXPECT_EQ(rect + rect1, Rectangle(1, 2, 8, 9));
}

TEST(RectangleTest, CompoundAddition) {
    Rectangle rect = Rectangle(1, 2, 3, 4);
    Rectangle rect2 = Rectangle(1, 6, 14, 10);
    rect += rect2;
    EXPECT_EQ(rect, Rectangle(1, 2, 14, 10));
}

TEST(RectangleTest, Subtraction) {
    Rectangle rect = Rectangle(1, 2, 3, 4);
    Rectangle rect1 = Rectangle(5, 6, 8, 9);
    EXPECT_EQ(rect - rect1, Rectangle(0, 0, 0, 0));
}

TEST(RectangleTest, CompoundSubtraction) {
    Rectangle rect = Rectangle(1, 2, 8, 9);
    Rectangle rect1 = Rectangle(5, 6, 8, 9);
    rect -= rect1;
    EXPECT_EQ(rect, Rectangle(5, 6, 8, 9));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "Running tests..." << std::endl;
    return RUN_ALL_TESTS();
}