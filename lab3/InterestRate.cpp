#include <string>
#include "InterestRate.h"

InterestRate::InterestRate(string t, double r) : type(t), rate(r) {}

double InterestRate::getCurrentRate() const {
    return rate;
}