#pragma once
#include <string>

class NutritionPlan {
private:
    std :: string details;

public:
    NutritionPlan(std :: string d);
    std :: string getDetails() const;
};