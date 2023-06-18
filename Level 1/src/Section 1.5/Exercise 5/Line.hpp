//
// Created by Michael Lewis on 6/9/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_LINE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_LINE_HPP

#include "Shape.hpp"

/**
 * A concrete CAD object
 */
class Line : public Shape
{
public:
    constexpr Line() = default;
    Line(const Line& source) = delete; // deleted only for simplicity. Example will be expanded in later exercises
    Line(Line&& source) = default; // move ctor is required when using shared pointers
    virtual ~Line() = default;

    // Operator overloads
    Line& operator=(const Line& source) = delete; // deleted only for simplicity. Example will be expanded in later exercises
    Line& operator=(Line&& source) = delete; // deleted only for simplicity. Example will be expanded in later exercises

    // Base class overrides
    void display(IODevice& ioDevice) const override;
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_LINE_HPP
