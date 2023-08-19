//
// Modern C++ Factory Pattern, which uses universal function wrappers to provide
// flexibility when constructing objects as well as to help reduce boilerplate
// code. This approach allows us to have a single factory and defer to clients in
// terms of how objects should be constructing by allowing them to leverage any type
// of std::function, function object, or std::bind mechanism during construction.
//
// Note - This Factory is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/19/23.
//

#include <memory>

#include "NewShapeFactory.hpp"

/**
 * Default ctor
 */
NewShapeFactory::NewShapeFactory() :
    circleFunc{ []() -> CirclePtr { return std::make_shared<Circle>(); }},
    lineFunc{ []() -> LinePtr  { return std::make_shared<Line>(); }},
    pointFunc{ []() -> PointPtr { return std::make_shared<Point>(); }}
{

}

/**
 * Overloaded ctor
 * @param _circleFunc A universal function wrapper responsible for creating a Circle
 * @param _lineFunc A universal function wrapper responsible for creating a Line
 * @param _pointFunc A universal function wrapper responsible for creating a Point
 */
NewShapeFactory::NewShapeFactory(CircleFunction&& _circleFunc, LineFunction&& _lineFunc, PointFunction&& _pointFunc)
    : circleFunc{std::move(_circleFunc)}, lineFunc{std::move(_lineFunc)}, pointFunc{std::move(_pointFunc)}
{

}

/**
 * Mutator that can be used to update the way a Circle is created by this Factory
 * @param _circleFunc  A universal function wrapper responsible for creating a Circle
 */
void NewShapeFactory::addCircleFunction(CircleFunction&& _circleFunc)
{
    circleFunc = std::move(_circleFunc);
}

/**
 * Mutator that can be used to update the way a Line is created by this Factory
 * @param _lineFunc A universal function wrapper responsible for creating a Line
 */
void NewShapeFactory::addLineFunction(LineFunction&& _lineFunc)
{
    lineFunc = std::move(_lineFunc);
}

/**
 * Mutator that can be used to update the way a Point is created by this Factory
 * @param _pointFunc A universal function wrapper responsible for creating a Point
 */
void NewShapeFactory::addPointFunction(PointFunction&& _pointFunc)
{
    pointFunc = std::move(_pointFunc);
}

/**
 * Factory function that uses the embedded universal function wrapper to create a Circle
 * @return A shared pointer for a Circle
 */
CirclePtr NewShapeFactory::createCircle() const
{
    return circleFunc();
}

/**
 * Factory function that uses the embedded universal function wrapper to create a Line
 * @return A shared pointer for a Line
 */
LinePtr NewShapeFactory::createLine() const
{
    return lineFunc();
}

/**
 * Factory function that uses the embedded universal function wrapper to create a Point
 * @return A shared pointer for a Point
 */
PointPtr NewShapeFactory::createPoint() const
{
    return pointFunc();
}
