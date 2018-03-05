#pragma once
#include "Vector.h"
#include <limits>

class LineSegment
{
public:
    LineSegment(Vector start, Vector end) : start(start), end(end) {};
    Vector start;
    Vector end;
    Vector Intersects(LineSegment line)
    {
        Vector r = end - start;
        Vector s = line.end - line.start;
        Vector qp = line.start - start;
        double rxs = r.Cross(s);
        double qpxr = qp.Cross(r);
        bool collinear = rxs == 0 && qpxr == 0;
        bool parallel = rxs == 0 && qpxr != 0;
        if (collinear || parallel)
        {
            return Vector(std::nan(""), std::nan(""));
        }
        double qpxs = qp.Cross(s);
        double t = qpxs / rxs;
        double u = qpxr / rxs;
        bool intersection = rxs != 0 && (0 <= t && t <= 1) && (0 <= u && u <= 1);
        if (intersection)
        {
            return Vector(start + t*r);
        }
        return Vector(std::nan(""), std::nan(""));
    }
};

