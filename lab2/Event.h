#pragma once
#include <string>
#include "Location.h"

using namespace std;


class Event {
private:
    string name;
    string date;
    Location* location;

public:
    Event(string n, string d, Location* loc);
    string getName() const;
    string getDate() const;
    Location* getLocation() const;
};