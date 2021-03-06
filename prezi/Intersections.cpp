#include "stdafx.h"
#include "Intersections.h"

std::vector<Point> Intersections::CalcIntersections(const std::vector<LineSegment>& lineSegments,
    const std::vector<Circle>& circles)
{
    std::unordered_set<Point> intersections;
    if (lineSegments.size() > 1)
    {
        for (unsigned int i = 0; i < lineSegments.size() - 1; ++i)
        {
            for (unsigned int j = i + 1; j < lineSegments.size(); ++j)
            {
                Point hit = lineSegments[i].Intersects(lineSegments[j]);
                if (std::isnan(hit.x))
                {
                    continue;
                }
                intersections.insert(hit);
            }
        }
    }
    if (circles.size() > 1)
    {
        for (unsigned int i = 0; i < circles.size() - 1; ++i)
        {
            for (unsigned int j = i + 1; j < circles.size(); ++j)
            {
                auto hits = circles[i].Intersects(circles[j]);
                for (const auto& hit : hits)
                {
                    intersections.insert(hit);
                }
            }
        }
    }
    for (unsigned int i = 0; i < circles.size(); ++i)
    {
        for (unsigned int j = 0; j < lineSegments.size(); ++j)
        {
            auto hits = circles[i].Intersects(lineSegments[j]);
            for (const auto& hit : hits)
            {
                intersections.insert(hit);
            }
        }
    }
    std::vector<Point> intersectionsCopy;
    intersectionsCopy.reserve(intersections.size());
    std::copy(intersections.begin(), intersections.end(),
        std::back_inserter(intersectionsCopy));
    return intersectionsCopy;
}