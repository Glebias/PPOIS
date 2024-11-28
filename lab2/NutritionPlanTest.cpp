#include <gtest/gtest.h>
#include "NutritionPlan.h"

TEST(NutritionPlanTest, GetDetails) {
    NutritionPlan plan("High protein diet");
    EXPECT_EQ(plan.getDetails(), "High protein diet");
}