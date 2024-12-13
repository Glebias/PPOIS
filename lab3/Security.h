#pragma once
#include <string>

using namespace std;

class Security {
public:
    string passwordHash;

    Security(const string& pass);
    bool checkPassword(const string& password) const;
};