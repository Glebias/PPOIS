#include <string>
#include "NutritionPlan.h"

using namespace std;

NutritionPlan::NutritionPlan(string d) : details(d) {}

string NutritionPlan::getDetails() const {
    return details;
}