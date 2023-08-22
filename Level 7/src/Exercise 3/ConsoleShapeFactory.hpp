//
// A factory class responsible for creating concrete shapes.
//
// Provides an interface for creating shapes while also providing an interface
// via the Template Method Pattern that allows this factory to specialize the
// type of Line that will be created by overriding the base class createStartPoint
// and createEndPoint functions
//
// Note - This Factory is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/11/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CONSOLESHAPEFACTORY_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CONSOLESHAPEFACTORY_HPP

#include "ShapeFactory.hpp"
#include "Circle.hpp"
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
    Point createPoint() override;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_CONSOLESHAPEFACTORY_HPP
