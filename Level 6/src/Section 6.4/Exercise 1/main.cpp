//
// Simple test case to illustrate the Prototype Pattern.
//
// Created by Michael Lewis on 8/7/23.
//

#include <iostream>
#include <memory>

#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
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

    std::cout << "*** Initial ShapeComposite***" << std::endl;
    print(shapeComposite);

    // Test the Prototype pattern via the copy ctor.
    ShapeComposite shapeComposite1 = ShapeComposite(shapeComposite);
    ShapeComposite shapeComposite2 = shapeComposite;

    // Modify contents of the original ShapeComposite and validate that the clone isn't modified
    p1->X(10);
    p1->Y(10);
    p2->X(10);
    p2->Y(10);
    line->p1(*p1);
    line->p2(*p2);
    circle->CenterPoint(*p1);
    circle->Radius(10);

    std::cout << "\n*** Modified ShapeComposite ***" << std::endl;
    print(shapeComposite);

    std::cout << "\n*** Cloned ShapeComposite - Cloned Via Copy Ctor ***" << std::endl;
    print(shapeComposite1);

    std::cout << "\n*** Cloned ShapeComposite - Cloned Via Assignment Operator ***" << std::endl;
    print(shapeComposite2);

    return 0;
}