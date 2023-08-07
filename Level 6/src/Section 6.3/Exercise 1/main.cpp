//
// Simple test case to illustrate the create and use of a Point via the Singleton pattern.
// Note - This exercise uses raw pointers simply to conform to the provided code in the lecture material.
// In a production application, I'd migrate these raw pointers to smart pointers instead.
//
// Created by Michael Lewis on 8/7/23.
//

#include <cassert>
#include <iostream>
#include <memory>

#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Shape.hpp"
#include "ShapeComposite.hpp"

void print(const ShapeComposite& sc1)
{
    for (const auto& it : sc1)
    {
        it->print();
    }
}

int main()
{
    // Write a test program to test the ShapeComposite.
    // Try to place shape composites in other shape composites.
    // In that test program write a Print(ShapeComposite sc) function that recursively prints the composite.
    std::shared_ptr<Point> p1{new Point{3, 4}};
    std::shared_ptr<Point> p2{new Point{2, 5}};
    std::shared_ptr<Line> line{new Line{*p1, *p2}};
    std::shared_ptr<Circle> circle{new Circle{*p1, 3}};

    ShapeComposite shapeComposite;
    shapeComposite.addShape(p1);
    shapeComposite.addShape(p2);
    shapeComposite.addShape(line);
    shapeComposite.addShape(circle);

    // Create another shape composite and add it to the existing shape composite
    std::shared_ptr<Point> p3{new Point{6, 6}};
    std::shared_ptr<Point> p4{new Point{7, 7}};
    std::shared_ptr<Line> line1{new Line{*p3, *p4}};
    std::shared_ptr<Circle> circle1{new Circle{*p3, 3}};

    std::shared_ptr<ShapeComposite> shapeComposite1 = std::make_shared<ShapeComposite>();
    shapeComposite1->addShape(p3);
    shapeComposite1->addShape(p4);
    shapeComposite1->addShape(line1);
    shapeComposite1->addShape(circle1);
    shapeComposite.addShape(shapeComposite1);

    print(shapeComposite);

    return 0;
}

