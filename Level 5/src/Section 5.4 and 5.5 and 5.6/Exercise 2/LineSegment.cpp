//
// Simple line class to help illustrate use cases of hash_value functions
//
// Created by Michael Lewis on 7/24/23.
//

#include "LineSegment.hpp"

/**
 * Default ctor that delegates construction of its start and end point to Point
 */
LineSegment::LineSegment() : start{Point()}, end{Point()}
{

}

/**
 * Copy ctor
 * @param other Another LineSegment whose data members will be deeply copied into this LineSegment
 */
LineSegment::LineSegment(const LineSegment &other)
{
    start = Point(other.start);
    end = Point(other.end);
}

/**
 * Move ctor
 * @param other Another LineSegment whose data members will be moved into this LineSegment
 */
LineSegment::LineSegment(LineSegment &&other) noexcept : start{std::move(other.start)}, end{std::move(other.end)}
{

}

/**
 * Overloaded ctor
 * @param start The start Point of this LineSegment
 * @param end The end Point of this LineSegment
 */
LineSegment::LineSegment(const Point &start, const Point &end) : start{start}, end{end}
{

}

std::size_t hash(const LineSegment& lineSegment)
{
    return hash_value(lineSegment.start, lineSegment.end);
}
