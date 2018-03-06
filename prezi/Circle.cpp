#pragma once
#include "stdafx.h"
#include "Circle.h"
#include <cmath>

std::vector<Point> Circle::Intersects(Circle& circle)
{
    double distance = center.Distance(circle.center);
    bool separateCircles = distance > (radius + circle.radius);
    bool circleContained = distance < std::abs(radius - circle.radius);
    if (separateCircles || circleContained)
    {
        return std::vector<Point>();
    }
    double base =
        ((radius * radius) - (circle.radius * circle.radius) + (distance * distance))
        / (2 * distance);
    double height = std::sqrt(radius * radius - base * base);
    Point p1 = (circle.center - center).Scale(base / distance) + center;
    double p2xh = height * (circle.center.y - center.y) / distance;
    double p2yh = height * (circle.center.x - center.x) / distance;
    if (p2xh == 0 && p2yh == 0)
    {
        return std::vector<Point> { p1 };
    }
    std::vector<Point> intersections
    {
        Point(p1.x + p2xh, p1.y - p2yh),
        Point(p1.x - p2xh, p1.y + p2yh)
    };
    return intersections;
}

std::vector<Point> Circle::Intersects(LineSegment& lineSegment)
{
    Point d = lineSegment.end - lineSegment.start;
    Point f = lineSegment.start - center;
    double a = d.Dot(d);
    double b = 2 * f.Dot(d);
    double c = f.Dot(f) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
    {
        return std::vector<Point>();
    }
    std::vector<Point> intersections;
    if (discriminant == 0)
    {
        double t0 = -b / (2 * a);
        if (t0 >= 0 && t0 <= 0)
        {
            Point p0 = lineSegment.start + d.Scale(t0);
            intersections.push_back(p0);
            return intersections;
        }
    }
    else
    {
        discriminant = std::sqrt(discriminant);
        double t1 = (-b - discriminant) / (2 * a);
        if (t1 >= 0 && t1 <= 1)
        {
            Point p1 = lineSegment.start + d.Scale(t1);
            intersections.push_back(p1);
        }
        double t2 = (-b + discriminant) / (2 * a);
        if (t2 >= 0 && t2 <= 1)
        {
            Point p2 = lineSegment.start + d.Scale(t2);
            intersections.push_back(p2);
        }
    }
    return intersections;
}
