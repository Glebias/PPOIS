#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Person {
protected:
    string name;
    string email;

public:
    Person(string n, string e);
    virtual void displayInfo() = 0; 
    virtual string GetName() = 0;
    string getEmail() const;
};

class Member : public Person {
private:
    int age;

public:
    Member(string n, string e, int a);
    void displayInfo() override;
    string GetName() override;
    int getAge() const;
    bool isAdult() const;
};

class Trainer : public Person {
protected:
    string specialization;

public:
    Trainer(string n, string e, string s);
    void displayInfo() override;
    string GetName() override;
    string GetSpecialization() const;
};

class Admin : public Person {
protected:
    int workTime;

public:
    Admin(string n, string e, int w = 40);
    void displayInfo() override;
    string GetName() override;
    int getWorkTime() const;
};

class Workout {
private:
    string type;
    int duration;

public:
    Workout(string t, int d);
    string getType() const;
    int getDuration() const;
    double durationInHours() const;
};

class FitnessClass {
private:
    string name;
    Trainer* trainer;

public:
    FitnessClass(string n, Trainer* tr);
    string getName() const;
    Trainer* getTrainer() const;
};

class Membership {
protected:
    string type;
    double fee;

public:
    Membership(string t, double f);
    string getType() const;
    double getFee() const;
};

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

class Equipment {
private:
    string name;
    int quantity;

public:
    Equipment(string n, int q);
    string getName() const;
    int getQuantity() const;
};

class Location {
private:
    string address;

public:
    Location(string addr);
    string getAddress() const;
};

class Event {
private:
    string name;
    string date;
    Location* location;

public:
    Event(string n, string d, Location* loc);
    string getName() const;
    string getDate() const;
    Location* getLocation() const;
};

class NutritionPlan {
private:
    string details;

public:
    NutritionPlan(string d);
    string getDetails() const;
};

class Schedule {
private:
    vector<Workout> workouts;

public:
    void addWorkout(const Workout& workout);
    const vector<Workout>& getWorkouts() const;
};

class Goal {
private:
    string description;

public:
    Goal(string desc);
    string getDescription() const;
};

class Feedback {
private:
    string comment;
    Member* member;

public:
    Feedback(string c, Member* m);
    string getComment() const;
    Member* getMember() const;
};

class Session {
private:
    string sessionDate;
    Trainer* trainer;

public:
    Session(string date, Trainer* tr);
    string getSessionDate() const;
    Trainer* getTrainer() const;
};

