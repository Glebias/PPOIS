#include <gtest/gtest.h>
#include "Equipment.h"

TEST(EquipmentTest, GetName) {
    Equipment equipment("Treadmill", 10);
    EXPECT_EQ(equipment.getName(), "Treadmill");
}

TEST(EquipmentTest, GetQuantity) {
    Equipment equipment("Dumbbells", 15);
    EXPECT_EQ(equipment.getQuantity(), 15);
}