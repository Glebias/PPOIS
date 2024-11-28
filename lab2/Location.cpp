#include "Location.h"
#include <string>

Location::Location(std :: string addr) : address(addr) {}

std :: string Location::getAddress() const {
    return address;
}