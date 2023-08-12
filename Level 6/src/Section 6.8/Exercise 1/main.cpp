//
// Simple test case to illustrate the Decorator Pattern.
//
// Created by Michael Lewis on 8/7/23.
//

#include <iostream>
#include <memory>

#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "NameDecorator.hpp"

// Decorate Circles using the NameDecorator
void test_DecorateCircle()
{
    std::shared_ptr<Circle> circle = std::make_shared<Circle>();
    circle->CenterPoint(Point(0, 0));
    circle->Radius(1);

    NameDecorator decorator(circle, "Circle");
    std::cout << "Shape Name: " << decorator.getName() << std::endl;
    decorator.setName("Updated Circle");
    std::cout << "Shape New Name: " << decorator.getName() << std::endl;
}

// Decorate Lines using the NameDecorator
void test_DecorateLine()
{
    std::shared_ptr<Line> line = std::make_shared<Line>();
    line->p1(Point(3, 4));
    line->p2(Point(5, 6));

    NameDecorator decorator(line, "Line");
    std::cout << "Shape Name: " << decorator.getName() << std::endl;
    decorator.setName("Updated Line");
    std::cout << "Shape New Name: " << decorator.getName() << std::endl;
}

// Decorate Points using the NameDecorator
void test_DecoratePoint()
{
    std::shared_ptr<Point> line = std::make_shared<Point>();
    line->X(3);
    line->Y(6);

    NameDecorator decorator(line, "Point");
    std::cout << "Shape Name: " << decorator.getName() << std::endl;
    decorator.setName("Updated Point");
    std::cout << "Shape New Name: " << decorator.getName() << std::endl;
}

int main()
{
    test_DecorateCircle();
    test_DecorateLine();
    test_DecoratePoint();

    return 0;
}