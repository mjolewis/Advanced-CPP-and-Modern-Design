//
// Created by Michael Lewis on 6/2/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_LINE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_LINE_HPP

#include <iostream>

#include "Shape.hpp"

/**
 * Line class that illustrates polymorphic functionality with variadic templates
 */
class Line : public Shape
{
public:
    constexpr Line() = default;
    ~Line() = default;

    void rotate(double d) const override {std::cout << "Line" << std::endl;}
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_LINE_HPP
