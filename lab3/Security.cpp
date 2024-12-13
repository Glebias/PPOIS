#include "Security.h"
#include <string>

using namespace std;

Security::Security(const string& pass) : passwordHash(pass) {}

bool Security::checkPassword(const string& password) const {
    return passwordHash == password;
}