//
// Created by Michael Lewis on 6/19/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP

#include "Shape.hpp"

/**
 * Base class used to illustrate type properties and type relationships
 */
class Point : public Shape
{
public:
    constexpr Point() = default;
    void draw() override {};
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP
