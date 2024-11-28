#pragma once
#include <vector>
#include "Workout.h"

using namespace std;

class Schedule {
private:
    vector<Workout> workouts;

public:
    void addWorkout(const Workout& workout);
    const vector<Workout>& getWorkouts() const;
};