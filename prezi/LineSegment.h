#pragma once
#include "Point.h"
#include <limits>

class LineSegment
{
public:
    LineSegment(Point start, Point end) : start(start), end(end) {};
    Point Intersects(const LineSegment& lineSegment) const;
    Point start;
    Point end;
};

