//
// Acts as the base object for derived shape classes.
// Note, the interface is slightly different from that provided by the homework.
// Per https://quantnet.com/threads/shape-clarification.55149/post-323347 this is expected
//
// Created by Michael Lewis on 8/4/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP

#include "ostream"

class Shape
{
public:
    virtual ~Shape() = default;

    // Print the shape information. This makes use of the polymorphic toString function.
    void print() const;

    // Virtual function to enable polymorphism
    virtual std::string toString() const;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP
