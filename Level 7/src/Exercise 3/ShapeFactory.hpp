//
// An abstract factory class responsible for creating concrete shapes.
//
// Provides an interface for creating shapes while also defining the structure
// of certain algorithms via the Template Method Pattern for creating Shapes
// such as lines and poly-lines
//
// Note - This Shape Factory is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/11/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SHAPEFACTORY_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SHAPEFACTORY_HPP

#include <iostream>

#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "PolyLine.hpp"

class ShapeFactory
{
public:
    ShapeFactory() = default;
    ShapeFactory(const ShapeFactory& other) = delete;
    ShapeFactory(ShapeFactory&& other) = delete;
    virtual ~ShapeFactory() = default;

    // Line is created using the template method pattern. Derived classes can customize
    // steps as needed by overriding createStartPoint and createEndPoint
    virtual Point createStartPoint();
    virtual Point createEndPoint();
    virtual Line createLine() final;

    virtual Circle createCircle() = 0;
    virtual Point createPoint() = 0;

    // Generic function to allow for any generic container to store the composite poly line
    template<typename T,
        template<typename S, typename Alloc> class Container,
        typename TAlloc = std::allocator<std::shared_ptr<Point>>>
    PolyLine<T, Container, TAlloc> createPolyLine()
    {
        PolyLine<Point, Container, TAlloc> polyLine;
        int numPoints = 0;

        std::cout << "How many points would you like to create? ";
        std::cin >> numPoints;

        for (int i = 0; i < numPoints; ++i)
        {
            const Point& point = createPoint();
            std::shared_ptr<Point> shapePtr = std::make_shared<Point>(point);
            polyLine.addShape(shapePtr);
        }

        return polyLine;
    }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SHAPEFACTORY_HPP
