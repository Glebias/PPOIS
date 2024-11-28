#include <string>
#include "Workout.h"

using namespace std;

Workout::Workout(string t, int d) : type(t), duration(d) {}

string Workout::getType() const {
    return type;
}

int Workout::getDuration() const {
    return duration;
}

double Workout::durationInHours() const {
    return duration / 60.0;
}