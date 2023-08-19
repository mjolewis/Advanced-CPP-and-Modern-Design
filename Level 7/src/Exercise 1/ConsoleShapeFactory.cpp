//
// A concrete factory responsible for creating shapes
//
// Note - This Factory is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/11/23.
//


#include <iostream>
#include <tuple>

#include "ShapeFactory.hpp"
#include "ConsoleShapeFactory.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"

/**
 * Default ctor
 */
ConsoleShapeFactory::ConsoleShapeFactory() : ShapeFactory()
{

}

/**
 * A factory method that is used to simplify the factory interface.
 * @return A std::tuple containing all the Shapes.
 */
std::tuple<Circle, Line, Point> ConsoleShapeFactory::createShapes()
{
    Circle circle = createCircle();
    Line line = createLine();
    Point point = createPoint();
    return std::make_tuple(circle, line, point);
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
 * A factory method to create a concrete Line
 * @return A newly created Line
 */
Line ConsoleShapeFactory::createLine()
{
    double xStart;
    std::cout << "Enter x coordinate for start point: ";
    std::cin >> xStart;

    double yStart;
    std::cout << "Enter y coordinate for start point: ";
    std::cin >> yStart;

    double xEnd;
    std::cout << "Enter x coordinate for start point: ";
    std::cin >> xEnd;

    double yEnd;
    std::cout << "Enter y coordinate for start point: ";
    std::cin >> yEnd;

    Point startPoint(xStart, yStart);
    Point endPoint(xEnd, yEnd);
    return {startPoint, endPoint};
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