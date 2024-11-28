#include "Equipment.h"


Equipment::Equipment(string n, int q) : name(n), quantity(q) {}

string Equipment::getName() const {
    return name;
}

int Equipment::getQuantity() const {
    return quantity;
}