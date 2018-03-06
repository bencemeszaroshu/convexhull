#pragma once
#include "Circle.h"
#include "LineSegment.h"
#include "Point.h"
#include <vector>

class Intersections
{
public:
    Intersections(std::vector<LineSegment>& lineSegments, std::vector<Circle>& circles)
    {
        points = CalcIntersections(lineSegments, circles);
    };
    std::vector<Point> points;
private:
    std::vector<Point> CalcIntersections(std::vector<LineSegment>& lineSegments,
        std::vector<Circle>& circles);
    int CalcBinomialCoefficent(int n, int k);
};

