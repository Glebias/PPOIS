#pragma once
#include <string>

using namespace std;

class Membership {
protected:
    string type;
    double fee;

public:
    Membership(string t, double f);
    string getType() const;
    double getFee() const;
};