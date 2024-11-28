#include "Event.h"
#include "Location.h"
#include <string>

using namespace std;

Event::Event(string n, string d, Location* loc) : name(n), date(d), location(loc) {}

string Event::getName() const {
    return name;
}

string Event::getDate() const {
    return date;
}

Location* Event::getLocation() const {
    return location;
}