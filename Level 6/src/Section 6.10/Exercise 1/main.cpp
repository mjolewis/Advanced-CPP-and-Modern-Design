//
// Visitor Pattern - Test leaf and composite objects
//
// Created by Michael Lewis on 8/15/23.
//

#include <memory>

#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "ShapeComposite.hpp"
#include "TranslateVisitor.hpp"
#include "PrintVisitor.hpp"

void test_VisitorPattern()
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

    // Translate the shapes in the composites
    TranslateVisitor translateVisitor{7};
    shapeComposite.accept(translateVisitor);

    // Print the shapes in the composite
    PrintVisitor printVisitor;
    shapeComposite.accept(printVisitor);
}

int main()
{
    test_VisitorPattern();
    return 0;
}