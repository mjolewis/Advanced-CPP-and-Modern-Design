//
// Illustrate how to use std::unordered_multiset and std::multiset using std::hash
// and user defined hash functions and measure processing speed to illustrate
// advantages of unordered containers.
//
// Created by Michael Lewis on 7/26/23.
//

#include <iostream>
#include <iterator>
#include <functional>
#include <unordered_set>
#include <set>

#include "Point.hpp"
#include "PointHasher.hpp"
#include "StopWatch.hpp"

// Part A - Create an unordered multiset of Point based on std::hash.
// Add many points to this multiset using insert() and emplace();
// remove elements from the multiset using erase() and clear().
// Measure processing time using std::chrono.
void test_std_hash()
{
    std::cout << "\n*** Test std::hash ***" << std::endl;
    std::unordered_multiset<Point, PointHasher, PointHasher> points;

    // Measure performance
    StopWatch stopWatch;
    stopWatch.Start();

    // Adding points using insert
    Point p1(1, 1);
    Point p2(2, 2);
    Point p3(3, 3);
    Point p4(4, 4);
    Point p5(5, 5);
    points.insert({p1, p2, p3, p4, p5});

    // Adding points using emplace
    Point p6(6, 6);
    Point p7(7, 7);
    Point p8(8, 8);
    Point p9(9, 9);
    Point p10(10, 10);
    points.emplace(p6);
    points.emplace(p7);
    points.emplace(p8);
    points.emplace(p9);
    points.emplace(p10);

    // Log Points to console to verify algos
    for (auto point : points) std::cout << point << std::endl;

    // Erase half of the points
    points.erase(p1);
    points.erase(p2);
    points.erase(p3);
    points.erase(p4);
    points.erase(p5);
    std::cout << "Size after erasing=" << points.size() << std::endl;

    // Clear all the other points
    points.clear();

    stopWatch.Stop();
    std::cout << "Size after clearing and erasing=" << points.size() << std::endl;
    std::cout << std::fixed << std::setw(11) << std::setprecision(6) << "Elapsed time in micros=" << stopWatch.ElapsedTime() << std::endl;
}

// Part B - Create your own hash functions and repeat part a) using multisets with
// these hashes as parameters. Measure processing time using std::chrono.
void test_custom_hash()
{
    std::cout << "\n*** Test custom hash ***" << std::endl;
    std::unordered_multiset<Point, Point, Point> points;

    // Measure performance
    StopWatch stopWatch;
    stopWatch.Start();

    // Adding points using insert
    Point p1(1, 1);
    Point p2(2, 2);
    Point p3(3, 3);
    Point p4(4, 4);
    Point p5(5, 5);
    points.insert({p1, p2, p3, p4, p5});

    // Adding points using emplace
    Point p6(6, 6);
    Point p7(7, 7);
    Point p8(8, 8);
    Point p9(9, 9);
    Point p10(10, 10);
    points.emplace(p6);
    points.emplace(p7);
    points.emplace(p8);
    points.emplace(p9);
    points.emplace(p10);

    // Log Points to console to verify algos
    for (auto point : points) std::cout << point << std::endl;

    // Erase half of the points
    points.erase(p1);
    points.erase(p2);
    points.erase(p3);
    points.erase(p4);
    points.erase(p5);
    std::cout << "Size after erasing=" << points.size() << std::endl;

    // Clear all the other points
    points.clear();

    stopWatch.Stop();
    std::cout << "Size after clearing and erasing=" << points.size() << std::endl;
    std::cout << std::fixed << std::setw(11) << std::setprecision(6) << "Elapsed time in micros=" << stopWatch.ElapsedTime() << std::endl;
}

// Part C - Repeat part a) using ‘standard’ STL multisets. Measure processing time using std::chrono.
void test_hash_with_multiset()
{
    std::cout << "\n*** Test std::multiset ***" << std::endl;
    std::multiset<Point> points;

    // Measure performance
    StopWatch stopWatch;
    stopWatch.Start();

    // Adding points using insert
    Point p1(1, 1);
    Point p2(2, 2);
    Point p3(3, 3);
    Point p4(4, 4);
    Point p5(5, 5);
    points.insert({p1, p2, p3, p4, p5});

    // Adding points using emplace
    Point p6(6, 6);
    Point p7(7, 7);
    Point p8(8, 8);
    Point p9(9, 9);
    Point p10(10, 10);
    points.emplace(p6);
    points.emplace(p7);
    points.emplace(p8);
    points.emplace(p9);
    points.emplace(p10);

    // Log Points to console to verify algos
    for (auto point : points) std::cout << point << std::endl;

    // Erase half of the points
    points.erase(p1);
    points.erase(p2);
    points.erase(p3);
    points.erase(p4);
    points.erase(p5);
    std::cout << "Size after erasing=" << points.size() << std::endl;

    // Clear all the other points
    points.clear();

    stopWatch.Stop();
    std::cout << "Size after clearing and erasing=" << points.size() << std::endl;
    std::cout << std::fixed << std::setw(11) << std::setprecision(6) << "Elapsed time in micros=" << stopWatch.ElapsedTime() << std::endl;
}

int main()
{
    test_std_hash();
    test_custom_hash();
    test_hash_with_multiset();
    return 0;
}