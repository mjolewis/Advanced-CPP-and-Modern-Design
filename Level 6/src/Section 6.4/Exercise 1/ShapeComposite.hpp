//
// Illustration of the Composite pattern, which allows clients to treat individual objects
// and compositions uniformly. It can be viewed as tree like structures that represents part-whole hierarchies.
//
// Created by Michael Lewis on 8/7/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SHAPECOMPOSITE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SHAPECOMPOSITE_HPP

#include <cstddef>
#include <list>
#include <memory>

#include "Shape.hpp"

class ShapeComposite : public Shape
{
private:
    std::list<std::shared_ptr<Shape>> shapes;

public:
    typedef std::list<std::shared_ptr<Shape>>::iterator iterator;
    typedef std::list<std::shared_ptr<Shape>>::const_iterator const_iterator;

    ShapeComposite();
    ShapeComposite(const ShapeComposite& other);
    ~ShapeComposite() override = default;

    // Operator Overloads
    ShapeComposite& operator=(const ShapeComposite& other);

    void addShape(const std::shared_ptr<Shape>& shape);
    iterator begin() noexcept;
    iterator end() noexcept;
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cBegin() const noexcept;
    const_iterator cEnd() const noexcept;
    size_t count() const;

    void print() const override;
    std::shared_ptr<Shape> clone() const override;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SHAPECOMPOSITE_HPP
