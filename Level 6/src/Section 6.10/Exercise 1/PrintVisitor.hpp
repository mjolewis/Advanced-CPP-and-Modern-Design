//
// Derived class for the Visitor Pattern. This class prints details about the objects that visit it
//
// Created by Michael Lewis on 8/15/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_PRINTVISITOR_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_PRINTVISITOR_HPP

#include "ShapeVisitor.hpp"

class Circle;
class Line;
class Point;
class ShapeComposite;

class PrintVisitor : public ShapeVisitor
{
public:
    PrintVisitor() = default;
    PrintVisitor(const PrintVisitor& other) = delete;
    PrintVisitor(PrintVisitor&& other) = delete;
    ~PrintVisitor() override = default;

    // Operator overloads
    PrintVisitor& operator=(const PrintVisitor& other) = delete;
    PrintVisitor& operator=(PrintVisitor&& other) = delete;

    // Visitor Pattern
    void visit(Circle& circle) override;
    void visit(Line& line) override;
    void visit(Point& point) override;
    void visit(ShapeComposite& shapeComposite) override;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_PRINTVISITOR_HPP
