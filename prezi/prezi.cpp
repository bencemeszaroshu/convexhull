// prezi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Circle.h"
#include "LineSegment.h"
#include "Point.h"
#include <fstream>
#include <iostream>

void ProcessInput(std::istream& input, int K, std::vector<LineSegment>& lineSegments, 
    std::vector<Circle>& circles);
std::vector<Point> CalcIntersections(std::vector<LineSegment>& lineSegments,
    std::vector<Circle>& circles);
int CalcBinomialCoefficent(int n, int k);

int main()
{
    std::ifstream testInput;
    testInput.open("D:\\Dokumentumok2\\prezi_hazi\\prezi\\Debug\\testinput.txt");
    if (!testInput.is_open())
    {
        return 0;
    }
    int K;
    testInput >> K;
    std::vector<LineSegment> lineSegments;
    lineSegments.reserve(K);
    std::vector<Circle> circles;
    circles.reserve(K);
    ProcessInput(testInput, K, lineSegments, circles);
    testInput.close();
    auto intersections = CalcIntersections(lineSegments, circles);

    int alma = 8;
}

void ProcessInput(std::istream& input, int K, std::vector<LineSegment>& lineSegments, std::vector<Circle>& circles)
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

std::vector<Point> CalcIntersections(std::vector<LineSegment>& lineSegments, std::vector<Circle>& circles)
{
    int maxLineSegmentIntersections = (lineSegments.size() * (lineSegments.size() + 1)) / 2;
    int maxCircleIntersections = 2 * CalcBinomialCoefficent(circles.size(), 2);
    int maxCirleLineSegmentIntersections = maxCircleIntersections;
    int maxIntersections = maxLineSegmentIntersections + maxCircleIntersections 
        + maxCirleLineSegmentIntersections;
    std::vector<Point> intersections;
    intersections.reserve(maxIntersections);
    for (unsigned int i = 0; i < lineSegments.size() - 1; ++i)
    {
        for (unsigned int j = i + 1; j < lineSegments.size(); ++j)
        {
            Point hit = lineSegments[i].Intersects(lineSegments[j]);
            if (std::isnan(hit.x))
            {
                continue;
            }
            intersections.push_back(hit);
        }
    }
    for (unsigned int i = 0; i < circles.size() - 1; ++i)
    {
        for (unsigned int j = i + 1; j < circles.size(); ++j)
        {
            auto hits = circles[i].Intersects(circles[j]);
            intersections.insert(intersections.end(), hits.begin(), hits.end());
        }
    }
    for (unsigned int i = 0; i < circles.size(); ++i)
    {
        for (unsigned int j = 0; j < lineSegments.size(); ++j)
        {
            auto hits = circles[i].Intersects(lineSegments[j]);
            intersections.insert(intersections.end(), hits.begin(), hits.end());
        }
    }
    return intersections;
}

int CalcBinomialCoefficent(int n, int k)
{
    int res = 1;
    if (k > n - k)
    {
        k = n - k;
    }
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}