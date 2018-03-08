#pragma once
#include "stdafx.h"
#include "LineSegment.h"

Point LineSegment::Intersects(const LineSegment& lineSegment) const
{
    Point r = end - start;
    Point s = lineSegment.end - lineSegment.start;
    Point qp = lineSegment.start - start;
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
        return Point(start + t * r);
    }
    return Point(std::nan(""), std::nan(""));
}
