//
// Created by Michael Lewis on 6/2/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CIRCLE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CIRCLE_HPP

#include <iostream>

#include "Shape.hpp"

class Circle : public Shape
{
public:
    constexpr Circle() = default;
    ~Circle() = default;

    void rotate(double d) const override {std::cout << "Circle\n";}
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_CIRCLE_HPP
