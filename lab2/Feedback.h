#pragma once
#include <string>
#include "Member.h"

using namespace std;

class Feedback {
private:
    string comment;
    Member* member;

public:
    Feedback(string c, Member* m);
    string getComment() const;
    Member* getMember() const;
};