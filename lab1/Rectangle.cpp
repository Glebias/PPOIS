#include <iostream>
#include "Rectangle.h"
#include <algorithm>
    

    Rectangle Rectangle::move(int dx, int dy) {

        x1 += dx;
        y1 += dy;
        x2 += dx;
        y2 += dy;
        return Rectangle(x1, y1, x2, y2);
    }


    Rectangle Rectangle::resize(int newWidth, int newHeight) {

        x2 = x1 + newWidth;
        y2 = y1 + newHeight;
        return Rectangle(x1, y1, x2, y2);
    }

    // Пре- и постинкремент
    Rectangle& Rectangle :: operator++() { // Преинкремент
        ++x2;
        ++y2;
        return *this;
    }

    Rectangle Rectangle :: operator++(int) { // Постинкремент
        Rectangle temp = *this;
        ++(*this);
        return temp;
    }

    // Пре- и постдекремент
    Rectangle& Rectangle :: operator--() { // Предекремент
        --x2;
        --y2;
        return *this;
    }

    Rectangle Rectangle :: operator--(int) { // Постдекремент
        Rectangle temp = *this;
        --(*this);
        return temp;
    }

    // Оператор +
    Rectangle operator+(const Rectangle& r1, const Rectangle& r2) {
        int newX1 = std::min(r1.x1, r2.x1);
        int newY1 = std::min(r1.y1, r2.y1);
        int newX2 = std::max(r1.x2, r2.x2);
        int newY2 = std::max(r1.y2, r2.y2);
        return Rectangle(newX1, newY1, newX2, newY2);
    }

    // Оператор +=
    Rectangle& Rectangle :: operator+=(const Rectangle& other) {
        x1 = std::min(x1, other.x1);
        y1 = std::min(y1, other.y1);
        x2 = std::max(x2, other.x2);
        y2 = std::max(y2, other.y2);
        return *this;
    }

    // Оператор -
    Rectangle operator-(const Rectangle& r1, const Rectangle& r2) {
        int newX1 = std::max(r1.x1, r2.x1);
        int newY1 = std::max(r1.y1, r2.y1);
        int newX2 = std::min(r1.x2, r2.x2);
        int newY2 = std::min(r1.y2, r2.y2);
        if (newX1 > newX2 || newY1 > newY2) {

            return Rectangle(0, 0, 0, 0);
        }
        return Rectangle(newX1, newY1, newX2, newY2);
    }


    // Оператор -=
    Rectangle& Rectangle :: operator-=(const Rectangle& other) {
        *this = *this - other;
        return *this;
    }
    bool Rectangle :: operator==(const Rectangle& other) const {
        return x1 == other.x1 && y1 == other.y1 && x2 == other.x2 && y2 == other.y2;
    }