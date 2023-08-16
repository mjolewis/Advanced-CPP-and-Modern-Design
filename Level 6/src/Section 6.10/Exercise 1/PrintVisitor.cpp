//
// Derived class for the Visitor Pattern. This class prints details about the objects that visit it
//
// Created by Michael Lewis on 8/15/23.
//

#include <iostream>

#include "PrintVisitor.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "ShapeComposite.hpp"

/**
 * Sends the specified object to the console out object
 * @param circle The object to be printed
 */
void PrintVisitor::visit(Circle &circle)
{
    std::cout << circle << std::endl;
}

/**
 * Sends the specified object to the console out object
 * @param line The object to be printed
 */
void PrintVisitor::visit(Line& line)
{
    std::cout << line << std::endl;
}

/**
 * Sends the specified object to the console out object
 * @param point The object to be printed
 */
void PrintVisitor::visit(Point &point)
{
    std::cout << point << std::endl;
}

/**
 * Sends the specified object to the console out object
 * @param shapeComposite The object to be printed
 * @note Function is silent. The composite acceptor dispatches individual shapes to their respective
 * acceptors, which subsequently dispatch to the object to the correct visit
 */
void PrintVisitor::visit(ShapeComposite &shapeComposite)
{
    // silent
}

