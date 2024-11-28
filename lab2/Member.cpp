#include "Member.h"
#include <iostream>

using namespace std;

Member::Member(string n, string e, int a) : Person(n, e), age(a) {}

void Member::displayInfo() {
    cout << "Member: " << name << ", Email: " << email << ", Age: " << age << endl;
}

string Member::GetName() {
    return name;
}

int Member::getAge() const {
    return age;
}

bool Member::isAdult() const {
    return age >= 18;
}
