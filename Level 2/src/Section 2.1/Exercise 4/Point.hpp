//
// Created by Michael Lewis on 6/19/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP

#include "Shape.hpp"

/**
 * Derived class used to illustrate supported operations on type traits
 */
class Point : public Shape
{
public:
    Point() {};
//    Point(const Point& source) = delete; // Explicitly deleted ctor
//    Point(Point&& source) noexcept = default;
    virtual void draw() override {};

    // Operator overloads
//    Point& operator=(const Point& source) = delete; // Explicitly deleted copy assignment operator
//    Point& operator=(Point&& source) = default;
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP
