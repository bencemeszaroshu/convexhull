#pragma once
#include <cmath>
#include <functional>
#include <iostream>
class Point
{
public:
    Point(double x, double y) : x(x), y(y) {};
    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    double operator*(const Point& p) const { return x * p.x + y * p.y; }
    bool operator==(const Point& p) const { return x == p.x && y == p.y; }
    bool operator<(const Point& p) const;
    double Cross(const Point& p) { return x * p.y - y * p.x; }
    int ClockWiseTurn(const Point& p1, const Point& p2) const;
    double Distance(const Point& p) const;
    double DistanceSquare(const Point& p) const;
    double Dot(const Point& p) const { return x * p.x + y * p.y; }
    Point Scale(double s) const { return Point(x * s, y * s); }
    friend Point operator*(const Point& p, double mult) { return Point(p.x * mult, p.y * mult); }
    friend Point operator*(double mult, const Point& p) { return Point(p.x * mult, p.y * mult); }
    friend std::ostream& operator<<(std::ostream& os, const Point& p)
    {
        return os << p.x << " " << p.y;
    }
    double x;
    double y;
};

// Note: Hash function to be able to store Points in unordered_set
template <>
struct std::hash<Point>
{
    std::size_t operator()(const Point& p) const
    {
        return ((std::hash<double>()(p.x)
            ^ std::hash<double>()(p.y) << 1)) >> 1;
    }
};

