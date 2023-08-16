//
// Base class for the Visitor Pattern
//
// Created by Michael Lewis on 8/15/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SHAPEVISITOR_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SHAPEVISITOR_HPP

class Circle;
class Point;
class Line;
class ShapeComposite;

class ShapeVisitor
{
public:
    ShapeVisitor() = default;
    ShapeVisitor(const ShapeVisitor& other) = delete;
    ShapeVisitor(ShapeVisitor&& other) = delete;
    virtual ~ShapeVisitor() = default;

    // Operator Overloads
    ShapeVisitor& operator=(const ShapeVisitor& other) = delete;
    ShapeVisitor& operator=(ShapeVisitor&& other) = delete;

    // Visitor Pattern
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Line& line) = 0;
    virtual void visit(Point& point) = 0;
    virtual void visit(ShapeComposite& shapeComposite) = 0;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SHAPEVISITOR_HPP
