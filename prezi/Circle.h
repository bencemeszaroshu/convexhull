#pragma once
#include "Point.h"

class Circle
{
public:
    Circle(Point center, double radious) : center(center), radius(radius) {};
    Point center;
    double radius;
};

