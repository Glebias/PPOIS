#pragma once
#include <string>
#include "Person.h"

using namespace std;

class Trainer : public Person {
protected:
    string specialization;

public:
    Trainer(string n, string e, string s);
    void displayInfo() override;
    string GetName() override;
    string GetSpecialization() const;
};