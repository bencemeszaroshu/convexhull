#pragma once
#include <cmath>
class Point
{
public:
    Point(double x, double y) : x(x), y(y) {};
    Point operator+(const Point& p) { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) { return Point(x - p.x, y - p.y); }
    double operator*(const Point& p) { return x * p.x + y * p.y; }
    bool operator==(const Point& p) { return x == p.x && y == p.y; }
    bool operator<(const Point& p);
    double Cross(const Point& p) { return x * p.y - y * p.x; }
    int ClockWiseTurn(const Point& p1, const Point& p2);
    double Distance(const Point& p);
    double DistanceSquare(const Point& p);
    double Dot(const Point& p) { return x * p.x + y * p.y; }
    Point Scale(double s) { return Point(x * s, y * s); }
    friend Point operator*(const Point& p, double mult) { return Point(p.x * mult, p.y * mult); }
    friend Point operator*(double mult, const Point& p) { return Point(p.x * mult, p.y * mult); }
    double x;
    double y;
};

