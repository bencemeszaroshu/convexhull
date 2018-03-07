#include "stdafx.h"
#include "ConvexHull.h"
#include <stack>
#include <algorithm>

std::vector<Point> ConvexHull::GrahamScan(std::vector<Point>& input)
{
    std::stack<Point> convexHull;
    if (input.size() < 3)
    {
        return input;
    }
    int mostBottomIndex = 0;
    for (unsigned int i = 1; i < input.size(); ++i)
    {
        if (input[i] < input[mostBottomIndex])
        {
            mostBottomIndex = i;
        }
    }
    std::iter_swap(input.begin(), input.begin() + mostBottomIndex);
    Point pivot = input[0];
    std::sort(input.begin() + 1, input.end(), [&pivot] (Point& lhs, Point& rhs)
    {
        int order = pivot.ClockWiseTurn(lhs, rhs);
        if (order == 0)
        {
            return pivot.DistanceSquare(lhs) < pivot.DistanceSquare(rhs);
        }
        return (order == -1);
    });
    convexHull.push(input[0]);
    convexHull.push(input[1]);
    convexHull.push(input[2]);
    for (unsigned int i = 3; i < input.size(); ++i)
    {
        Point top = convexHull.top();
        convexHull.pop();
        while ((convexHull.top()).ClockWiseTurn(top, input[i]) != -1)
        {
            top = convexHull.top();
            convexHull.pop();
        }
        convexHull.push(top);
        convexHull.push(input[i]);
    }
    std::vector<Point> convexHullCopy;
    unsigned int size = convexHull.size();
    convexHullCopy.reserve(size);
    for (unsigned i = 0; i < size; ++i)
    {
        convexHullCopy.push_back(convexHull.top());
        convexHull.pop();
    }
    return convexHullCopy;
}

double ConvexHull::CalcArea()
{
    double area = 0;
    for (unsigned int i = 0; i < points.size() - 1; ++i)
    {
        area += points[i].x * points[i + 1].y - points[i + 1].x * points[i].y;
    }
    area +=
        points[points.size() - 1].x * points[0].y - points[0].x * points[points.size() - 1].y;
    area = std::abs(area) / 2.0;
    return area;
}
