#pragma once
#include "Vector.h"

class Circle
{
public:
    Circle(Vector center, double radious) : center(center), radius(radius) {};
    Vector center;
    double radius;
};

