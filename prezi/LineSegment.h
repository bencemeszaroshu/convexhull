#pragma once
#include "Point.h"
#include <limits>

class LineSegment
{
public:
    LineSegment(Point start, Point end) : start(start), end(end) {};
    Point start;
    Point end;
    Point Intersects(LineSegment line)
    {
        Point r = end - start;
        Point s = line.end - line.start;
        Point qp = line.start - start;
        double rxs = r.Cross(s);
        double qpxr = qp.Cross(r);
        bool collinear = rxs == 0 && qpxr == 0;
        bool parallel = rxs == 0 && qpxr != 0;
        if (collinear || parallel)
        {
            return Point(std::nan(""), std::nan(""));
        }
        double qpxs = qp.Cross(s);
        double t = qpxs / rxs;
        double u = qpxr / rxs;
        bool intersection = rxs != 0 && (0 <= t && t <= 1) && (0 <= u && u <= 1);
        if (intersection)
        {
            return Point(start + t*r);
        }
        return Point(std::nan(""), std::nan(""));
    }
};

