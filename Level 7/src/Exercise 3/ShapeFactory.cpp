//
// An abstract factory class responsible for creating concrete shapes.
//
// Provides an interface for creating shapes while also defining the structure
// of certain algorithms via the Template Method Pattern for creating Shapes
// such as lines and poly-lines
//
// Note - This Shape Factory is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/11/23.
//

#include "ShapeFactory.hpp"
#include "Point.hpp"
#include "Line.hpp"


/**
 * Creates a point. One step of the template method to create a line.
 * This allows derived classes to override specific steps in the algorithm as needed
 * @return A Point
 */
Point ShapeFactory::createStartPoint()
{
    return createPoint();
}

/**
 * Creates a point. One step of the template method to create a line.
 * This allows derived classes to override specific steps in the algorithm as needed
 * @return A Point
 */
Point ShapeFactory::createEndPoint()
{
    return createPoint();
}

/**
 * Creates a line by implementing the Template Method Pattern
 * @return
 */
Line ShapeFactory::createLine()
{
    Point startPoint = createStartPoint();
    Point endPoint = createEndPoint();
    return Line{startPoint, endPoint};
}


