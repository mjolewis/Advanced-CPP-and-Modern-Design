//
// Analyze modifying algorithms and illustrate basic use cases
//
// Created by Michael Lewis on 7/15/23.
//

#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <string>
#include <regex>

#include <boost/algorithm/string.hpp>

#include "Point.hpp"

// Define aliases
using Set = std::set<int>;

// Part A - Consider the set S1 = {a,b,c,d,e,k} and the set S2 = {a,e}. Remove those elements
// from S1 that are in S2. The output set is {b,c,d,k}.
void test_remove()
{
    Set s1{'a','b','c','d','e','k'};
    Set s2{'a','e'};
    Set s3;

    // Per https://quantnet.com/threads/6-remove-elements-from-set.54827/post-321856
    // We are allowed to copy the elements into a new set.
    std::copy_if(s1.begin(), s1.end(),
                   std::inserter(s3, s3.begin()), [&](int element) { return !s2.contains(element); });

    std::cout << "Set{";
    for (auto element : s3)
    {
        std::cout << (char) element << ", ";
    }
    std::cout << "}" << std::endl;
}

// Helper function that creates an array of points
std::array<Point, 10> createPoints()
{
    std::array<Point, 10> points{};
    for (int i = 0; i < 5; ++i) points[i] = Point(i, i);

    // Create duplicate Points
    for (int i = 5; i < 10; ++i) points[i] = Point(i - 5, i - 5);

    return points;
}

// Part B - Create an array of points, transform it into a set, and filter points that are not within
// a specific distance of some predefined point.
void test_point()
{
    std::array<Point, 10> points = createPoints();
    std::set<Point> set;

    for (auto point : points) set.insert(point);
    for (auto point : set) std::cout << point;

    // Predefined target point
    Point targetPoint(2, 2);
    double targetDistance = 2;
    erase_if(set, [&](const Point& p) { return targetPoint.distance(p) > targetDistance; });
    std::cout << "\nRemoving points not within target distance:" << std::endl;
    for (auto point : set) std::cout << point;
}

// Part C - Trim all leading and trailing blanks (space, tabs etc.) from the string.
void test_trim_blanks()
{
    // Regex looking for whitespace (s+ is space one or more times)
    std::regex r("\\s+");
    std::string s1 = " test     test\t   test\n";
    std::cout << "\ns1 before trim: " << s1 << std::endl;
    s1 = std::regex_replace(s1, r, "");
    std::cout << "s1 after trim: " << s1 << std::endl;
}

// Part C - Trim all leading and trailing blanks based on a unary predicate
void test_trim_blanks_unary_predicate()
{
    std::string s1 = " test     test\t   test\n";
    std::cout << "\ns1 before trim: " << s1 << std::endl;
    s1.erase(std::remove_if(s1.begin(), s1.end(), ::isspace), s1.end());
    std::cout << "s1 after trim: " << s1 << std::endl;
}

// Part C - Produce a vector of strings from a character-separated string.
void test_vector_of_strings()
{
    std::string s1 = "This is going to be a vector";
    std::string separator = " ";
    std::vector<std::string> words;

    boost::split(words, s1, boost::is_any_of(separator));
    for (const auto& word : words)
    {
        std::cout << word << ", ";
    }
}

// Part C - Join two strings.
void test_join_strings()
{
    std::string s1 = "Hello";
    std::string s2 = "World";
    std::cout << s1 + " " + s2 << std::endl;
}

int main()
{
    test_remove();
    test_point();
    test_trim_blanks();
    test_trim_blanks_unary_predicate();
    test_vector_of_strings();
    test_join_strings();
    return 0;
}
