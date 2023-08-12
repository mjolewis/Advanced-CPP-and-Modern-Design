//
// An abstract Shape Decorator responsible for decorating Shape names
//
// Created by Michael Lewis on 8/11/23.
//

#include <memory>

#include "ShapeDecorator.hpp"
#include "Shape.hpp"

/**
 * Default ctor
 */
ShapeDecorator::ShapeDecorator() : Shape(), shape{}
{

}

/**
 * Overloaded ctor
 * @param _shape A Shape shared pointer whose wrapped object will be decorated
 */
ShapeDecorator::ShapeDecorator(const std::shared_ptr<Shape>& _shape) : Shape(), shape{_shape}
{

}

const std::shared_ptr<Shape>& ShapeDecorator::getShape() const
{
    return shape;
}

void ShapeDecorator::setShape(const std::shared_ptr<Shape>& _shape)
{
    shape = _shape;
}