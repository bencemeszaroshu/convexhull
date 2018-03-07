// prezi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Circle.h"
#include "ConvexHull.h"
#include "Intersections.h"
#include "LineSegment.h"
#include "Point.h"
#include <algorithm>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <iostream>

void ProcessInput(std::istream& input, unsigned int K, std::vector<LineSegment>& lineSegments, 
    std::vector<Circle>& circles);
void PrintOutput(std::ostream& output, Intersections& intersections, ConvexHull& convexHull);

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
    std::cout << std::fixed;
    std::cout << std::setprecision(4);
    PrintOutput(std::cout, intersections, convexHull);
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

void PrintOutput(std::ostream& output, Intersections & intersections, ConvexHull & convexHull)
{
    output << intersections.points.size() << "\n";
    std::copy(intersections.points.begin(), intersections.points.end(), 
        std::ostream_iterator<Point>(output, "\n"));
    output << convexHull.points.size() << "\n";
    std::copy(convexHull.points.begin(), convexHull.points.end(),
        std::ostream_iterator<Point>(output, "\n"));
    output << convexHull.area << "\n";
}
