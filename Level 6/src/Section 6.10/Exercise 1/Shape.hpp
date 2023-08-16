//
// Acts as the base object for derived shape classes. Shape is an interface.
//
// Created by Michael Lewis on 8/15/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP

class ShapeVisitor;

class Shape
{
public:
    virtual ~Shape() = default;

    // Print the shape information.
    virtual void print() const = 0;
    virtual void accept(ShapeVisitor& visit) = 0;
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP
