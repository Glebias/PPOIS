#include <string>
#include "Person.h"
#include "Trainer.h"
#include <iostream>

using namespace std;

Trainer::Trainer(string n, string e, string s) : Person(n, e), specialization(s) {}

void Trainer::displayInfo() {
    cout << "Trainer: " << name << ", Email: " << email << ", Specialization: " << specialization << endl;
}

string Trainer::GetName() {
    return name;
}

string Trainer::GetSpecialization() const {
    return specialization;
}