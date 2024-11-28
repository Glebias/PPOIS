#pragma once
#include <string>

using namespace std;

class Goal {
private:
    string description;

public:
    Goal(string desc);
    string getDescription() const;
};