//
// Created by Michael Lewis on 6/9/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CIRCLE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CIRCLE_HPP

#include "Shape.hpp"

/**
 * A concrete CAD object
 */
class Circle : public Shape
{
public:
    constexpr Circle() = default;
    Circle(const Circle& source) = delete; // deleted only for simplicity. Example will be expanded in later exercises
    Circle(Circle&& source) = default; // move ctor is required when using shared pointers
    virtual ~Circle() = default;

    // Operator overloads
    Circle& operator=(const Circle& source) = delete; // deleted only for simplicity. Example will be expanded in later exercises
    Circle& operator=(Circle&& source) = delete; // deleted only for simplicity. Example will be expanded in later exercises

    // Base class overrides
    void display(IODevice& ioDevice) const override;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_CIRCLE_HPP
