#include "Goal.h"
#include <string>

using namespace std;

Goal::Goal(string desc) : description(desc) {}

string Goal::getDescription() const {
    return description;
}