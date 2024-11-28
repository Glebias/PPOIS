#include "Person.h"

Person::Person(string n, string e) : name(n), email(e) {}

string Person :: GetName() { return name; }

string Person::getEmail() const {
    return email;
}