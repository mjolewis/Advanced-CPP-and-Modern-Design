//
// An concrete Decorator responsible for decorating Shape names
//
// Created by Michael Lewis on 8/11/23.
//

#include <iostream>
#include <memory>
#include <utility>

#include "NameDecorator.hpp"
#include "ShapeDecorator.hpp"
#include "Shape.hpp"

/**
 * Default ctor
 */
NameDecorator::NameDecorator() : ShapeDecorator(), name{}
{

}

/**
 * Overloaded ctor
 * @param shape A shared pointer that wraps the shape to be decorated
 * @param name The name of the shape
 */
NameDecorator::NameDecorator(const std::shared_ptr<Shape> &shape, std::string  name)
    : ShapeDecorator(shape), name{std::move(name)}
{

}

/**
 * Returns the name of the Shape
 * @return The name of the Shape
 */
std::string NameDecorator::getName() const
{
    return name;
}

/**
 * Sets the name for the Shape
 * @param _name The name of the Shape
 */
void NameDecorator::setName(std::string _name)
{
    name = std::move(_name);
}

/**
* Implements the Prototype pattern by creating a deep clone of this Point
* @return A deep clone of this Point wrapped in a Shared Pointer
*/
std::shared_ptr<Shape> NameDecorator::clone() const
{
    return std::make_shared<NameDecorator>(*this);
}

void NameDecorator::print() const
{
    std::cout << "Shape Name: " << name << std::endl;
}
