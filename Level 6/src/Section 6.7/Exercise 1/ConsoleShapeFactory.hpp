//
// A concrete factory responsible for creating shapes
//
// Note - This Strategy is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/11/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CONSOLESHAPEFACTORY_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CONSOLESHAPEFACTORY_HPP

#include "ShapeFactory.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"

class ConsoleShapeFactory : public ShapeFactory
{
public:
    ConsoleShapeFactory();
    ConsoleShapeFactory(const ConsoleShapeFactory& other) = delete;
    ConsoleShapeFactory(ConsoleShapeFactory&& other) = delete;
    ~ConsoleShapeFactory() override = default;

    // Operator Overloads
    ConsoleShapeFactory& operator=(const ConsoleShapeFactory& other) = delete;
    ConsoleShapeFactory& operator=(ConsoleShapeFactory&& other) = delete;

    // Function Overrides
    Circle createCircle() override;
    Line createLine() override;
    Point createPoint() override;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_CONSOLESHAPEFACTORY_HPP
