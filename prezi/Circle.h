#pragma once
#include "LineSegment.h"
#include "Point.h"
#include <vector>

class Circle
{
public:
    Circle(Point center, double radius) : center(center), radius(radius) {};
    std::vector<Point> Intersects(const Circle& circle) const;
    std::vector<Point> Intersects(const LineSegment& lineSegment) const;
    Point center;
    double radius;
};

