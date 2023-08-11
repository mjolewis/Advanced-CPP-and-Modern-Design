//
// Simple test case to illustrate the Strategy Pattern.
//
// Created by Michael Lewis on 8/7/23.
//

#include <cassert>
#include <iostream>
#include <memory>

#include "DistanceStrategy.hpp"
#include "ExactDistance.hpp"
#include "ApproximateDistance.hpp"
#include "Point.hpp"

// Test exact distance using the Strategy Pattern for Phytagoras distance
void test_ExactDistance()
{
    std::cout << "*** Exact Distance ***" << std::endl;

    DistanceStrategy::setStrategy(std::make_shared<ExactDistance>());

    // Create a new point and calculate the exact distance
    Point p1{3, 4};
    double distance = p1.distance();
    std::cout << "Exact distance between Point(3,4) and origin:" << distance << std::endl;
    assert(5 == distance);

    // Create a second point and calculate the exact distance
    Point p2{5, 4};
    distance = p1.distance(p2);
    std::cout << "Exact distance between Point(3,4) and modified origin of (5,2):" << distance << std::endl;
    assert(2 == distance);
}

// Test exact distance using the Strategy Pattern for taxicab distance (aka Manhattan distance)
void test_ApproximateDistance()
{
    std::cout << "*** Approximate Distance ***" << std::endl;

    DistanceStrategy::setStrategy(std::make_shared<ApproximateDistance>());

    // Create a new point and calculate the approximate distance
    Point p1{3, 4};
    double distance = p1.distance();
    std::cout << "Approximate distance between Point(3,4) and origin:" << distance << std::endl;
    assert(7 == distance);

    // Create a second point and calculate the approximate distance
    Point p2{5, 4};
    distance = p1.distance(p2);
    std::cout << "Approximate distance between Point(3,4) and modified origin of (5,2):" << distance << std::endl;
    assert(2 == distance);
}

int main()
{
    // Write a program that calculates the distance between two points using the different strategies.
    test_ExactDistance();
    test_ApproximateDistance();

    return 0;
}