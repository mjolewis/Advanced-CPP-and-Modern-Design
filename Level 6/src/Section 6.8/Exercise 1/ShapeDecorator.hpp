//
// An abstract Shape Decorator responsible for decorating Shape names
//
// Created by Michael Lewis on 8/11/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SHAPEDECORATOR_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SHAPEDECORATOR_HPP

#include <memory>

#include "Shape.hpp"

class ShapeDecorator : public Shape
{
private:
    std::shared_ptr<Shape> shape;

public:
    ShapeDecorator();
    explicit ShapeDecorator(const std::shared_ptr<Shape>& _shape);
    ShapeDecorator(const ShapeDecorator& other) = default;
    ShapeDecorator(ShapeDecorator&& other) = default;
    ~ShapeDecorator() override = default;

    // Operator Overloads
    ShapeDecorator& operator=(const ShapeDecorator& other) = default;
    ShapeDecorator& operator=(ShapeDecorator&& other) = default;

    // Accessors and Mutators
    const std::shared_ptr<Shape>& getShape() const;
    void setShape(const std::shared_ptr<Shape>& _shape);
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SHAPEDECORATOR_HPP
