#include<string>
#include "BankEmployee.h"

// Конструктор
BankEmployee::BankEmployee(string id, string n, double sal)
    : employeeId(id), name(n), salary(sal) {}

// Метод для получения идентификатора сотрудника
string BankEmployee::getEmployeeId() const {
    return employeeId;
}

// Метод для получения имени сотрудника
string BankEmployee::getName() const {
    return name;
}

// Метод для получения зарплаты сотрудника
double BankEmployee::getSalary() const {
    return salary;
}

// Метод для изменения зарплаты сотрудника
void BankEmployee::setSalary(double newSalary) {
    salary = newSalary;
}