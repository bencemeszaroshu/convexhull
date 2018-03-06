// prezi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Circle.h"
#include "ConvexHull.h"
#include "Intersections.h"
#include "LineSegment.h"
#include "Point.h"
#include <fstream>
#include <iostream>

void ProcessInput(std::istream& input, unsigned int K, std::vector<LineSegment>& lineSegments, 
    std::vector<Circle>& circles);

int main()
{
    std::ifstream testInput;
    testInput.open("D:\\Dokumentumok2\\prezi_hazi\\prezi\\Debug\\testinput.txt");
    if (!testInput.is_open())
    {
        return 0;
    }
    unsigned int K;
    testInput >> K;
    std::vector<LineSegment> lineSegments;
    lineSegments.reserve(K);
    std::vector<Circle> circles;
    circles.reserve(K);
    ProcessInput(testInput, K, lineSegments, circles);
    testInput.close();
    Intersections intersections(lineSegments, circles);
    ConvexHull convexHull(intersections.points);
    int alma = 56;
}

void ProcessInput(std::istream& input, unsigned int K, std::vector<LineSegment>& lineSegments, std::vector<Circle>& circles)
{
    for (unsigned int i = 0; i < K; ++i)
    {
        char type;
        input >> type;
        if (type == 'C')
        {
            double x;
            double y;
            double radius;
            input >> x >> y >> radius;
            circles.push_back(Circle(Point(x, y), radius));

        }
        else if (type == 'L')
        {
            double x1;
            double x2;
            double y1;
            double y2;
            input >> x1 >> y1 >> x2 >> y2;
            lineSegments.push_back(LineSegment(Point(x1, y1), Point(x2, y2)));
        }
    }
}