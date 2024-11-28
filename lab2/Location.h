#pragma once
#include <string>

class Location {
private:
    std :: string address;

public:
    Location(std :: string addr);
    std :: string getAddress() const;
};