#include <vector>
#include "Workout.h"
#include "Schedule.h"

void Schedule::addWorkout(const Workout& workout) {
    workouts.push_back(workout);
}

const vector<Workout>& Schedule::getWorkouts() const {
    return workouts;
}