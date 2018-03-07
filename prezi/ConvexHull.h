#pragma once
#include "Point.h"
#include <vector>
class ConvexHull
{
public:
    ConvexHull(std::vector<Point>& inputPoints);
    std::vector<Point> points;
    double area;
private:
    double CalcArea();
    std::vector<Point> GrahamScan(std::vector<Point>& input);
};

