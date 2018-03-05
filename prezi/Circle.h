#pragma once
#include "Point.h"
#include <vector>

class Circle
{
public:
    Circle(Point center, double radius) : center(center), radius(radius) {};
    std::vector<Point> Intersects(Circle circle);
    Point center;
    double radius;
};

