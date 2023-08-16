//
// Composite pattern, to allow clients to treat individual objects and compositions uniformly.
// It can be viewed as tree like structures that represents part-whole hierarchies.
//
// Created by Michael Lewis on 8/15/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SHAPECOMPOSITE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SHAPECOMPOSITE_HPP


#include <cstddef>
#include <list>
#include <memory>

#include "Shape.hpp"

class ShapeVisitor;

class ShapeComposite : public Shape
{
private:
    std::list<std::shared_ptr<Shape>> shapes;

public:
    typedef std::list<std::shared_ptr<Shape>>::iterator iterator;
    typedef std::list<std::shared_ptr<Shape>>::const_iterator const_iterator;

    ShapeComposite();
    ShapeComposite(const ShapeComposite& other) = default;
    ~ShapeComposite() override = default;

    void addShape(const std::shared_ptr<Shape>& shape);
    iterator begin() noexcept;
    iterator end() noexcept;
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cBegin() const noexcept;
    const_iterator cEnd() const noexcept;
    size_t count() const;

    // Overridden Functions
    void print() const override;
    void accept(ShapeVisitor& visit) override;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SHAPECOMPOSITE_HPP
