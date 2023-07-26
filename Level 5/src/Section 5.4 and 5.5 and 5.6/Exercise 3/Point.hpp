//
// Simple point class to help illustrate use cases of hash_value functions and std::hash
//
// Created by Michael Lewis on 7/15/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP

#include <cstddef>
#include <ostream>

#include <boost/functional/hash.hpp>

class Point
{
private:
    double xCoordinate;
    double yCoordinate;

public:
    Point() = default;
    Point(const Point& source) = default;
    Point(Point&& source) = default;
    Point(const double& xCoordinate, const double& yCoordinate);
    ~Point() = default;

    // Operator overloads
    Point& operator=(const Point& other) = default;
    Point& operator=(Point&& other) = default;
    bool operator<(const Point& point) const;
    std::size_t operator()(const Point& point) const noexcept;
    bool operator()(const Point& lhs, const Point& rhs) const noexcept;

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
