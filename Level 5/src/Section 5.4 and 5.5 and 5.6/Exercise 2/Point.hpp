//
// Simple point class to help illustrate use cases of hash_value functions
//
// Created by Michael Lewis on 7/15/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP

#include <cstddef>
#include <ostream>

#include <boost/functional/hash.hpp>

// Forward declarations to allow LineSegment to delegate to Points hash_value function
class LineSegment;

class Point
{
private:
    double xCoordinate;
    double yCoordinate;

    // Friends
    friend class LineSegment;

public:
    Point() = default;
    Point(const Point& source) = default;
    Point(Point&& source) = default;
    Point(const double& xCoordinate, const double& yCoordinate);
    ~Point() = default;

    // Operator overloads
    Point& operator=(const Point& source) = default;
    Point& operator=(Point&& source) = default;
    bool operator<(const Point& other) const;

    // Core functionality
    double distance(const Point& other) const;

    // Friends
    friend bool equal(const Point& p1, const Point& p2);
    friend std::ostream& operator<<(std::ostream& ostream, const Point& point);
    friend std::size_t hash_value(const Point& point);
    friend std::size_t hash_value(const Point& lhs, const Point& rhs);

    // Accessors
    double X() const noexcept;
    double Y() const noexcept;

    // Mutators
    void X(const double& x);
    void Y(const double& y);
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP
