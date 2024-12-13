#pragma once
#include <string>

using namespace std;

class BankEmployee {
public:
    string employeeId;
    string name;
    double salary;

    BankEmployee(string id, string n, double sal);
    string getEmployeeId() const;
    string getName() const;
    double getSalary() const;
    void setSalary(double newSalary);
};