#include "stdafx.h"
#include "Circle.h"

std::vector<Point> Circle::Intersects(Circle circle)
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
    double height = sqrt(radius * radius - base * base);
    Point p1 = (circle.center - center).Scale(base / distance) + center;
    if (distance == radius + circle.radius)
    {
        return std::vector<Point> { p1 };
    }
    double p2xh = height * (circle.center.y - center.y) / distance;
    double p2yh = height * (circle.center.x - center.x) / distance;
    std::vector<Point> intersections
    {
        Point(p1.x + p2xh, p1.y + p2yh),
        Point(p1.x - p2xh, p1.y - p2yh)
    };
    return intersections;
}
