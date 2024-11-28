#pragma once
#include <string>
#include "Trainer.h"

using namespace std;

class Session {
private:
    string sessionDate;
    Trainer* trainer;

public:
    Session(string date, Trainer* tr);
    string getSessionDate() const;
    Trainer* getTrainer() const;
};