#pragma once
#include <string>

using namespace std;


class Equipment {
private:
    string name;
    int quantity;

public:
    Equipment(string n, int q);
    string getName() const;
    int getQuantity() const;
};