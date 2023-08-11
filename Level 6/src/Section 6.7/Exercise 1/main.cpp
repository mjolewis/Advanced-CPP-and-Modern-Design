//
// Simple test case to illustrate the Factory Pattern.
//
// Created by Michael Lewis on 8/7/23.
//

#include <iostream>
#include <memory>

#include "ShapeFactory.hpp"
#include "ConsoleShapeFactory.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"

// Create Circles using the factory pattern
void test_CircleFactory()
{
    std::shared_ptr<ShapeFactory> factory = std::make_shared<ConsoleShapeFactory>();
    Circle c = factory->createCircle();

    std::cout << "Circle - Center Point: " << c.CenterPoint() << ", Radius: " << c.Radius() << std::endl;
}

// Create Lines using the factory pattern
void test_LineFactory()
{
    std::shared_ptr<ShapeFactory> factory = std::make_shared<ConsoleShapeFactory>();
    Line line = factory->createLine();

    std::cout << "Line - Point1: " << line.p1() << ", Point2: " << line.p2() << std::endl;
}

// Create Points using the factory pattern
void test_PointFactory()
{
    std::shared_ptr<ShapeFactory> factory = std::make_shared<ConsoleShapeFactory>();
    Point point = factory->createPoint();

    std::cout << "Point(" << point.X() << ", " << point.Y() << ")" << std::endl;
}

int main()
{
    test_CircleFactory();
    test_LineFactory();
    test_PointFactory();

    return 0;
}