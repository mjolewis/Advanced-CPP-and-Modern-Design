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
    // Note - Per https://quantnet.com/threads/std-shared_ptr-is-incompatible-with-shapecomposite.50089/post-323451
    // We are no longer explicitly deleting copy ctor or assignment operator

    void addShape(const std::shared_ptr<Shape>& shape);
    iterator begin() noexcept;
    iterator end() noexcept;
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cBegin() const noexcept;
    const_iterator cEnd() const noexcept;
    size_t count() const;

    void print() const override;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SHAPECOMPOSITE_HPP
