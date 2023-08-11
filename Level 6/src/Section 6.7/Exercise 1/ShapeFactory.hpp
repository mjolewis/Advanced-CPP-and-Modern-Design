//
// An abstract factory class responsible for creating concrete shapes
//
// Note - This Shape Factory is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/11/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SHAPEFACTORY_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SHAPEFACTORY_HPP

#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"

class ShapeFactory
{
public:
    ShapeFactory() = default;
    ShapeFactory(const ShapeFactory& other) = delete;
    ShapeFactory(ShapeFactory&& other) = delete;
    virtual ~ShapeFactory() = default;

    virtual Circle createCircle() = 0;
    virtual Line createLine() = 0;
    virtual Point createPoint() = 0;
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SHAPEFACTORY_HPP
