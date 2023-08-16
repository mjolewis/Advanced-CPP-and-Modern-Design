//
// Derived class for the Visitor Pattern. This class modifies each object that visits it
//
// Created by Michael Lewis on 8/15/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_TRANSLATEVISITOR_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_TRANSLATEVISITOR_HPP

#include "ShapeVisitor.hpp"

class Circle;
class Line;
class Point;
class ShapeComposite;

class TranslateVisitor : public ShapeVisitor
{
private:
    int distance;
public:
    TranslateVisitor() = default;
    TranslateVisitor(const int distance = 0);
    TranslateVisitor(const TranslateVisitor& other) = delete;
    TranslateVisitor(TranslateVisitor&& other) = delete;
    ~TranslateVisitor() override = default;

    // Operator Overloads
    TranslateVisitor& operator=(const TranslateVisitor& other) = delete;
    TranslateVisitor& operator=(TranslateVisitor&& other) = delete;

    // Visitor Pattern
    virtual void visit(Circle& circle);
    virtual void visit(Line& line);
    virtual void visit(Point& point);
    virtual void visit(ShapeComposite& shapeComposite);
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_TRANSLATEVISITOR_HPP
