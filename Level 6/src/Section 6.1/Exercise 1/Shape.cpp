//
// Acts as the base object for derived shape classes.
// Note, the interface is slightly different from that provided by the homework.
// Per https://quantnet.com/threads/shape-clarification.55149/post-323347 this is expected
//
// Created by Michael Lewis on 8/7/23.
//

#include <iostream>

#include "Shape.hpp"

/**
 * Returns a string representation of this Shape.
 * @return A string representation of this Shape.
 * @note Uses the Template Method Pattern to delegate functionality to the polymorphic toString function.
 */
void Shape::print() const
{
    std::cout << toString() << std::endl;
}

/**
 * Creates and returns a string representation of this Shapes ID.
 * @return A string representation of this Shapes ID.
 */
std::string Shape::toString() const
{
    return "Shape";
}
