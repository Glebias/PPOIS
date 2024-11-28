#include "Trainer.h"
#include "FitnessClass.h"
#include <string>

using namespace std;

FitnessClass::FitnessClass(string n, Trainer* tr) : name(n), trainer(tr) {}

string FitnessClass::getName() const {
    return name;
}

Trainer* FitnessClass::getTrainer() const {
    return trainer;
}