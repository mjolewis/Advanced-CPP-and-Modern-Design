//
// Simple test case to illustrate the creation and use of a Point via the Singleton pattern.
//
// Created by Michael Lewis on 8/7/23.
//

#include <cassert>
#include <iostream>

#include "OriginPoint.hpp"
#include "Point.hpp"

int main()
{
    // Test creating a single origin point
    Point *origin = Singleton<Point>::instance();
    std::cout << "origin: " << *origin << std::endl;

    // Create a new point so that we can calculate the distance to the origin
    Point p1{3, 4};
    double distance = p1.distance();
    std::cout << "Distance between Point(3,4) and origin:" << distance << std::endl;
    assert(5 == distance);

    // Modify the origin and recalculate the distance
    origin->X(5);
    origin->Y(4);
    distance = p1.distance();
    std::cout << "Distance between Point(3,4) and modified origin of (5,2):" << distance << std::endl;
    assert(2 == distance);

    return 0;
}

