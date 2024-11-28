#include <string>
#include "Trainer.h"
#include "Session.h"

using namespace std;

Session::Session(string date, Trainer* tr) : sessionDate(date), trainer(tr) {}

string Session::getSessionDate() const {
    return sessionDate;
}

Trainer* Session::getTrainer() const {
    return trainer;
}