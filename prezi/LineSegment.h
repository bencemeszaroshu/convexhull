#pragma once
#include "Point.h"
#include <limits>

class LineSegment
{
public:
    LineSegment(Point start, Point end) : start(start), end(end) {};
    Point Intersects(LineSegment line);
    Point start;
    Point end;
};

