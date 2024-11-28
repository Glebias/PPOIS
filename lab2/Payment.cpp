#include <string>
#include "Membership.h"
#include "Member.h"
#include "Payment.h"

Payment::Payment(string t, double f, string d, Member* m) : Membership(t, f), date(d), member(m) {}

string Payment::GetDate() const {
    return date;
}

bool Payment::IsFeeCorrect() const {
    return fee >= 50;
}

Member* Payment::getMember() const {
    return member;
}