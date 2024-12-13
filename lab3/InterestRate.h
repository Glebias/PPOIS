#pragma once
#include <string>

using namespace std;

class InterestRate {
public:
    string type; 
    double rate;

    InterestRate(string t, double r);
    double getCurrentRate() const;
};