//
// Simple line class to help illustrate use cases of hash_value functions
//
// Created by Michael Lewis on 7/24/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_LINESEGMENT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_LINESEGMENT_HPP

#include <cstddef>

#include <boost/functional/hash.hpp>

#include "Point.hpp"

class LineSegment
{
private:
    Point start;
    Point end;

public:
    LineSegment();
    LineSegment(const LineSegment& other);
    LineSegment(LineSegment&& other) noexcept ;
    LineSegment(const Point& start, const Point& end);
    ~LineSegment() = default;

    // Friends
    friend std::size_t hash(const LineSegment& lineSegment);
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_LINESEGMENT_HPP
