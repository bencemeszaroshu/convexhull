#pragma once
#include <math.h>
class Point
{
public:
    Point(double x, double y) : x(x), y(y) {};
    double x;
    double y;
    Point operator+(Point p) { return Point(x + p.x, y + p.y); };
    Point operator-(Point p) { return Point(x - p.x, y - p.y); };
    double operator*(Point p) { return x * p.x + y * p.y; };
    bool operator==(Point p) { return x == p.x && y == p.y; };
    double Cross(Point p) { return x * p.y - y * p.x; };
    double Distance(Point p)
    {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
    Point Scale(double s) { return Point(x * s, y * s); };
    friend Point operator*(Point p, double mult) { return Point(p.x * mult, p.y * mult); };
    friend Point operator*(double mult, Point p) { return Point(p.x * mult, p.y * mult); };
};

