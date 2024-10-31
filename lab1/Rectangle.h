#pragma once

    class Rectangle {
    private:
        int x1, y1, x2, y2;

    public:

        Rectangle(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}


        void getCoordinates() const;



        Rectangle move(int dx, int dy);


        Rectangle resize(int newWidth, int newHeight);


        Rectangle& operator++();

        Rectangle operator++(int);


        Rectangle& operator--();

        Rectangle operator--(int);


        friend Rectangle operator+(const Rectangle& r1, const Rectangle& r2);


        Rectangle& operator+=(const Rectangle& other);


        friend Rectangle operator-(const Rectangle& r1, const Rectangle& r2);


        Rectangle& operator-=(const Rectangle& other);


        bool operator==(const Rectangle& other) const;
    };