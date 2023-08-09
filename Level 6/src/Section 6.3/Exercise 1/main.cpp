//
// Simple test case to illustrate the Composite Pattern
//
// Created by Michael Lewis on 8/7/23.
//

#include <iostream>
#include <memory>

#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Shape.hpp"
#include "ShapeComposite.hpp"

// Recursively prints Shapes held in a ShapeComposite object (handles both leaf nodes and composite nodes)
void print(const ShapeComposite& sc1)
{
    for (const auto& it : sc1)
    {
        it->print();
    }
}

int main()
{
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

