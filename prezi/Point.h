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
    bool operator<(const Point& p)
    {
        if (y != p.y)
        {
            return y < p.y;
        }
        return x < p.x;
    }
    double Cross(const Point& p) { return x * p.y - y * p.x; }
    double Distance(const Point& p)
    {
        return std::sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
    double DistanceSquare(const Point& p)
    {
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
    }
    double Dot(const Point& p) { return x * p.x + y * p.y; }
    Point Scale(double s) { return Point(x * s, y * s); }
    friend Point operator*(const Point& p, double mult) { return Point(p.x * mult, p.y * mult); }
    friend Point operator*(double mult, const Point& p) { return Point(p.x * mult, p.y * mult); }
    double x;
    double y;
};

