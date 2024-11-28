#pragma once
#include <string>
#include "Membership.h"
#include "Member.h"

using namespace std;

class Payment : protected Membership {
private:
    string date;
    Member* member;

public:
    Payment(string t, double f, string d, Member* m);
    string GetDate() const;
    bool IsFeeCorrect() const;
    Member* getMember() const;
};