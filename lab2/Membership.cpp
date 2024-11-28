#include "Membership.h"

Membership::Membership(string t, double f) : type(t), fee(f) {}

string Membership::getType() const {
    return type;
}

double Membership::getFee() const {
    return fee;
}
