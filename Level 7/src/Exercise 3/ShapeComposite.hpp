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

template<typename T,
        template<typename S, typename Alloc> class Container,
        typename TAlloc = std::allocator<std::shared_ptr<T>>>
class ShapeComposite : public Shape
{
private:
    Container<std::shared_ptr<T>, TAlloc> shapes;  //store shapes in a generic container

public:
    typedef Container<std::shared_ptr<T>, TAlloc>::iterator iterator;
    typedef Container<std::shared_ptr<T>, TAlloc>::const_iterator const_iterator;

    ShapeComposite();
    ~ShapeComposite() override = default;

    void addShape(const std::shared_ptr<T>& shape);

    iterator begin() noexcept;
    iterator end() noexcept;
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cBegin() const noexcept;
    const_iterator cEnd() const noexcept;
    size_t count() const;

    void print() const override;
};

// ********** Template Definitions **********
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SHAPECOMPOSITE_CPP
#include "ShapeComposite.cpp"
#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SHAPECOMPOSITE_CPP

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SHAPECOMPOSITE_HPP
