// prezi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LineSegment.h"
#include "Point.h"
#include <iostream>

int main()
{
    LineSegment l1(Point(0, 0), Point(5, 5));
    LineSegment l2(Point(0, 5), Point(5, 0));

    auto v = l1.Intersects(l2);

    std::cout << v.x << " " << v.y << std::endl;

    return 0;
}

