#pragma once
#include "Vector.h"
#include <limits>

class Line
{
public:
    Line(Vector v1, Vector v2) :v1(v1), v2(v2) {};
    Vector v1;
    Vector v2;
    Vector Intersects(Line l)
    {
        Vector r = v2 - v1;
        Vector s = l.v2 - l.v1;
        double rxs = r.Cross(s);
        double qpxr = (l.v1 - v1).Cross(r);
        bool collinear = rxs == 0 && qpxr == 0;
        bool parallel = rxs == 0 && qpxr != 0;
        if (collinear || parallel)
        {
            return Vector(std::nan(""), std::nan(""));
        }
        double t = (l.v1 - v1).Cross(s) / rxs;
        double u = (l.v1 - v1).Cross(r) / rxs;
        bool intersection = rxs != 0 && (0 <= t && t <= 1) && (0 <= u && u <= 1);
        if (intersection)
        {
            return Vector(v1 + t*r);
        }
        return Vector(std::nan(""), std::nan(""));
    }
};

