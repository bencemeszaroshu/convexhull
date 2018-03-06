#pragma once
#include "LineSegment.h"
#include "Point.h"
#include <vector>

class Circle
{
public:
    Circle(Point center, double radius) : center(center), radius(radius) {};
    std::vector<Point> Intersects(Circle circle);
    std::vector<Point> Intersects(LineSegment lineSegment);
    Point center;
    double radius;
};

