// prezi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LineSegment.h"
#include "Vector.h"
#include <iostream>

int main()
{
    LineSegment l1(Vector(0, 0), Vector(5, 5));
    LineSegment l2(Vector(0, 5), Vector(5, 0));

    auto v = l1.Intersects(l2);

    std::cout << v.x1 << " " << v.x2 << std::endl;

    return 0;
}

