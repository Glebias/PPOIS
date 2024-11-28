#pragma once
#include <string>
#include "Person.h"

using namespace std;

class Admin : public Person {
protected:
    int workTime;

public:
    Admin(string n, string e, int w = 40);
    void displayInfo() override;
    string GetName() override;
    int getWorkTime() const;
};