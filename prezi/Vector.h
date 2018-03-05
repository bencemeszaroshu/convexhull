#pragma once
class Vector
{
public:
    Vector(double x1, double x2) : x1(x1), x2(x2) {};
    double x1;
    double x2;
    Vector operator+(Vector v) { return Vector(x1 + v.x1, x2 + v.x2); };
    Vector operator-(Vector v) { return Vector(x1 - v.x1, x2 - v.x2); };
    double operator*(Vector v) { return x1 * v.x1 + x2 * v.x2; };
    friend Vector operator*(Vector v, double mult) { return Vector(v.x1 * mult, v.x2 * mult); };
    friend Vector operator*(double mult, Vector v) { return Vector(v.x1 * mult, v.x2 * mult); };
    double Cross(Vector v) { return x1 * v.x2 - x2 * v.x1; };
    bool operator==(Vector v) { return x1 == v.x1 && x2 == v.x2; };
};

