#include <string>
#include "Person.h"
#include "Admin.h"
#include <iostream>

using namespace std;

Admin::Admin(string n, string e, int w) : Person(n, e), workTime(w) {}

void Admin::displayInfo() {
    cout << "Admin: " << name << ", Email: " << email << ", Work time: " << workTime << " hours" << endl;
}

string Admin::GetName() {
    return name;
}

int Admin::getWorkTime() const {
    return workTime;
}