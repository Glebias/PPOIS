#pragma once
#include <string>

using namespace std;

class Workout {
private:
    string type;
    int duration;

public:
    Workout(string t, int d);
    string getType() const;
    int getDuration() const;
    double durationInHours() const;
};