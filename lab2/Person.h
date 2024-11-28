#pragma once
#include <string>

using namespace std;

class Person {
protected:
    string name;
    string email;

public:
    Person(string n, string e);
    virtual void displayInfo() = 0; 
    virtual string GetName() = 0;
    string getEmail() const;
};