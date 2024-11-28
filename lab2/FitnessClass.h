#pragma once
#include <string>
#include "Trainer.h"

using namespace std;

class FitnessClass {
private:
    string name;
    Trainer* trainer;

public:
    FitnessClass(string n, Trainer* tr);
    string getName() const;
    Trainer* getTrainer() const;
};