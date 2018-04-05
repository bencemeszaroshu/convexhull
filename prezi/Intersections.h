#pragma once
#include "Circle.h"
#include "LineSegment.h"
#include "Point.h"
#include <algorithm>
#include <unordered_set>
#include <vector>

class Intersections
{
public:
    Intersections(const std::vector<LineSegment>& lineSegments, const std::vector<Circle>& circles)
    {
        points = CalcIntersections(lineSegments, circles);
    };
    std::vector<Point> points;
private:
    std::vector<Point> CalcIntersections(const std::vector<LineSegment>& lineSegments,
        const std::vector<Circle>& circles);
};

