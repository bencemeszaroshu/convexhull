#include "stdafx.h"
#include "Point.h"

bool Point::operator<(const Point& p) const
{
    if (y != p.y)
    {
        return y < p.y;
    }
    return x < p.x;
}

int Point::ClockWiseTurn(const Point& p1, const Point& p2) const
{
    double area = (p1.x - x) * (p2.y - y) - (p1.y - y) * (p2.x - x);
    if (area > 0)
    {
        return -1;
    }
    else if (area < 0)
    {
        return 1;
    }
    return 0;
}

double Point::Distance(const Point& p) const
{
    return std::sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}

double Point::DistanceSquare(const Point& p) const
{
    return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
}