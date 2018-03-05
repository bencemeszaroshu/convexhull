#pragma once
class Vector
{
public:
    Vector(double x1, double x2) : x1(x1), x2(x2) {};
    double x1;
    double x2;
    Vector operator+(Vector y) { return Vector(x1 + y.x1, x2 + y.x2); };
    Vector operator-(Vector y) { return Vector(x1 - y.x1, x2 - y.x2); };
    double operator*(Vector y) { return x1 * y.x1 + x2 * y.x2; };
    friend Vector operator*(Vector y, double mult) { return Vector(y.x1 * mult, y.x2 * mult); };
    friend Vector operator*(double mult, Vector y) { return Vector(y.x1 * mult, y.x2 * mult); };
    double Cross(Vector y) { return x1 * y.x1 - x2 * y.x2; };
    bool operator= (Vector y) 
    { 
        return ((x1 - y.x1) < 1e-10) && ((x2 - y.x2) < 1e-10);
    };
};

