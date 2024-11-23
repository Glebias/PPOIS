#include "SportClub.h"

Person::Person(string n, string e) : name(n), email(e) {}

Member::Member(string n, string e, int a) : Person(n, e), age(a) {}

string Person :: GetName() { return name; }

string Person::getEmail() const {
    return email;
}

void Member::displayInfo() {
    cout << "Member: " << name << ", Email: " << email << ", Age: " << age << endl;
}

string Member::GetName() {
    return name;
}

int Member::getAge() const {
    return age;
}

bool Member::isAdult() const {
    return age >= 18;
}


Trainer::Trainer(string n, string e, string s) : Person(n, e), specialization(s) {}

void Trainer::displayInfo() {
    cout << "Trainer: " << name << ", Email: " << email << ", Specialization: " << specialization << endl;
}

string Trainer::GetName() {
    return name;
}

string Trainer::GetSpecialization() const {
    return specialization;
}

Admin::Admin(string n, string e, int w) : Person(n, e), workTime(w) {}

void Admin::displayInfo() {
    cout << "Admin: " << name << ", Email: " << email << ", Work time: " << workTime << " hours" << endl;
}

string Admin::GetName() {
    return name;
}

int Admin::getWorkTime() const {
    return workTime;
}

Workout::Workout(string t, int d) : type(t), duration(d) {}

string Workout::getType() const {
    return type;
}

int Workout::getDuration() const {
    return duration;
}

double Workout::durationInHours() const {
    return duration / 60.0;
}

FitnessClass::FitnessClass(string n, Trainer* tr) : name(n), trainer(tr) {}

string FitnessClass::getName() const {
    return name;
}

Trainer* FitnessClass::getTrainer() const {
    return trainer;
}

Membership::Membership(string t, double f) : type(t), fee(f) {}

string Membership::getType() const {
    return type;
}

double Membership::getFee() const {
    return fee;
}

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

Equipment::Equipment(string n, int q) : name(n), quantity(q) {}

string Equipment::getName() const {
    return name;
}

int Equipment::getQuantity() const {
    return quantity;
}

Location::Location(string addr) : address(addr) {}

string Location::getAddress() const {
    return address;
}

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

NutritionPlan::NutritionPlan(string d) : details(d) {}

string NutritionPlan::getDetails() const {
    return details;
}

void Schedule::addWorkout(const Workout& workout) {
    workouts.push_back(workout);
}

const vector<Workout>& Schedule::getWorkouts() const {
    return workouts;
}

Goal::Goal(string desc) : description(desc) {}

string Goal::getDescription() const {
    return description;
}

Feedback::Feedback(string c, Member* m) : comment(c), member(m) {}

string Feedback::getComment() const {
    return comment;
}

Member* Feedback::getMember() const {
    return member;
}

Session::Session(string date, Trainer* tr) : sessionDate(date), trainer(tr) {}

string Session::getSessionDate() const {
    return sessionDate;
}

Trainer* Session::getTrainer() const {
    return trainer;
}