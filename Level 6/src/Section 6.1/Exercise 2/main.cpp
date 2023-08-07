//
// Tests the distance formula of Point and the delegation functionality within Line to determine the distance
// between the start point and end point
//
// Created by Michael Lewis on 8/7/23.
//

#include <cassert>
#include <cmath>

#include "Point.hpp"
#include "Line.hpp"

// Test the distance between a point and the origin
void test_distanceToOrigin()
{
    Point point{3, 4};
    double distance = point.distance();
    assert(5 == distance);
}

// Test the distance between two points
void test_distanceBetweenPoints()
{
    Point p1{3, 4};
    Point p2{1, -3};
    double distance = p1.distance(p2);
    assert(sqrt(53) == distance);
}

// Test the length between a start and end point
void test_length()
{
    Point p1{3, 4};
    Point p2{1, -3};
    Line line{p1, p2};
    double length = line.length();
    assert(sqrt(53) == length);
}

int main()
{
    test_distanceToOrigin();
    test_distanceBetweenPoints();
    return 0;
}
