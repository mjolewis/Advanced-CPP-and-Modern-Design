//
// A factory class responsible for creating concrete shapes.
//
// Provides an interface for creating shapes while also providing an interface
// via the Template Method Pattern that allows this factory to specialize the
// type of Line that will be created by overriding the base class createStartPoint
// and createEndPoint functions
//
// Note - This Factory is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/11/23.
//


#include <iostream>

#include "ShapeFactory.hpp"
#include "ConsoleShapeFactory.hpp"
#include "Circle.hpp"
#include "Point.hpp"

/**
 * Default ctor
 */
ConsoleShapeFactory::ConsoleShapeFactory() : ShapeFactory()
{

}

/**
 * A factory method to create a concrete Circle
 * @return A newly created Circle
 */
Circle ConsoleShapeFactory::createCircle()
{
    double x;
    std::cout << "Enter x coordinate for center point: ";
    std::cin >> x;

    double y;
    std::cout << "Enter y coordinate for center point: ";
    std::cin >> y;

    double radius;
    std::cout << "Enter radius: ";
    std::cin >> radius;

    Point centerPoint(x, y);
    return {centerPoint, radius};
}

/**
 * A factory method to create a concrete Point
 * @return A newly created Point
 */
Point ConsoleShapeFactory::createPoint()
{
    double x;
    std::cout << "Enter x coordinate: ";
    std::cin >> x;

    double y;
    std::cout << "Enter y coordinate: ";
    std::cin >> y;

    return {x, y};
}