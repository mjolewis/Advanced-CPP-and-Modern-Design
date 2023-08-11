//
// Acts as the base object for derived shape classes. Shape is an interface as it only
// contains pure virtual functions.
//
// Created by Michael Lewis on 8/4/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP

#include <memory>

class Shape
{
public:
    virtual ~Shape() = default;

    virtual void print() const = 0;
    virtual std::shared_ptr<Shape> clone() const = 0;
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP
