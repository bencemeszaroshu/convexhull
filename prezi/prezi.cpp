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

void ProcessInput(std::istream& input, unsigned int numberOfShapes,
    std::vector<LineSegment>& lineSegments, std::vector<Circle>& circles);
void PrintOutput(std::ostream& output, Intersections& intersections, ConvexHull& convexHull);

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        std::cout << std::endl << "Usage: prezi.exe <INPUTFILE> <OUTPUTFILE>" << std::endl;
        return 1;
    }
    std::vector<LineSegment> lineSegments;
    std::vector<Circle> circles;
    std::ifstream inputFile(argv[1]);
    if (inputFile.is_open())
    {
        unsigned int numberOfShapes;
        inputFile >> numberOfShapes;
        lineSegments.reserve(numberOfShapes);
        circles.reserve(numberOfShapes);
        ProcessInput(inputFile, numberOfShapes, lineSegments, circles);
    }
    else
    {
        std::cout << std::endl << "Couldn't open input file" << std::endl;
        return 1;
    }
    Intersections intersections(lineSegments, circles);
    ConvexHull convexHull(intersections.points);
    std::ofstream resultFile(argv[2]);
    if (resultFile.is_open())
    {
        resultFile << std::fixed;
        resultFile << std::setprecision(4);
        PrintOutput(resultFile, intersections, convexHull);
    }
    else
    {
        std::cout << std::endl << "Couldn't open output file" << std::endl;
        return 1;
    }
    return 0;
}

void ProcessInput(std::istream& input, unsigned int numberOfShapes, 
    std::vector<LineSegment>& lineSegments, std::vector<Circle>& circles)
{
    for (unsigned int i = 0; i < numberOfShapes; ++i)
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

void PrintOutput(std::ostream& output, Intersections& intersections, ConvexHull& convexHull)
{
    output << intersections.points.size() << "\n";
    std::copy(intersections.points.begin(), intersections.points.end(), 
        std::ostream_iterator<Point>(output, "\n"));
    output << convexHull.points.size() << "\n";
    std::copy(convexHull.points.begin(), convexHull.points.end(),
        std::ostream_iterator<Point>(output, "\n"));
    output << convexHull.area << "\n";
}
