//
// Illustrate how to create user defined hash codes for user defined types
// Note - This illustration will use Boost and STL
//
// Created by Michael Lewis on 7/24/23.
//

#include <cassert>
#include <cstddef>
#include <iostream>
#include <list>

#include <boost/functional/hash.hpp>

#include "LineSegment.hpp"
#include "Point.hpp"
#include "PointHash.hpp"

// Part A - Create hashes for Point and LineSegment using boost::hash_combine. T
void test_linesegment_hash_delegation()
{
    Point p1(1, 2);
    Point p2(3, 4);

    LineSegment l1(p1, p2);

    // Inspect hash_value function for individual Points
    size_t hash_value_p1 = hash_value(p1);
    size_t hash_value_p2 = hash_value(p1);
    std::cout << "P1 Hash:" << hash_value_p1 << std::endl;
    std::cout << "P2 Hash:" << hash_value_p2 << std::endl;

    // Inspect hash_value function for groups of Points
    size_t hash_value_points = hash_value(p1, p2);
    std::cout << "Points Hash:" << hash_value_points << std::endl;

    // Call friend function of LineSegement
    size_t hash_value_line = hash(l1);
    std::cout << "Line Hash:" << hash_value_line << std::endl;

    assert(hash_value_points == hash_value_line);
}

// Part B - Create a list of Point instances and compute its hash_value using boost::hash_range().
void test_list_of_points()
{
    std::list<Point> points;

    for (int i = 0; i < 10; ++i)
    {
        points.emplace_back(i, i);
    }

    std::size_t hash_value = boost::hash_range(points.begin(), points.end());
    std::cout << "Hash Range: " << hash_value << std::endl;
}

// Part C - Use PointHash to create and return a hash value
// Per https://quantnet.com/threads/5-4-2.51598/post-316886
// We can use PointHash as is and don't need a custom implementation
void test_point_hash()
{
    Point point(1, 2);

    PointHash pointHash;
    std::size_t hash_value = pointHash(point);
    std::cout << "Hash Value: " << hash_value << std::endl;
}

int main()
{
    test_linesegment_hash_delegation();
    test_list_of_points();
    test_point_hash();
    return 0;
}