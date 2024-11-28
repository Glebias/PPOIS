#pragma once
#include <string>
#include "Person.h"

using namespace std;

class Member : public Person {
private:
    int age;

public:
    Member(string n, string e, int a);
    void displayInfo() override;
    string GetName() override;
    int getAge() const;
    bool isAdult() const;
};