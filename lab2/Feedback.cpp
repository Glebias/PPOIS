#include <string>
#include "Member.h"
#include "Feedback.h"

using namespace std;

Feedback::Feedback(string c, Member* m) : comment(c), member(m) {}

string Feedback::getComment() const {
    return comment;
}

Member* Feedback::getMember() const {
    return member;
}