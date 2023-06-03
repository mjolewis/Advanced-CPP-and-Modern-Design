//
// Created by Michael Lewis on 6/2/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP

#include <functional>

// Alias for a function wrapper
template<typename T>
using VoidFunctionType = std::function<void (const T& t)>;

/**
 * A base class that illustrates how to emulate
 * polymorphism using function wrappers.
 *
 * Improves performance by eliminating virtual function calls
 */
template<typename T>
class Shape
{
protected:
    VoidFunctionType<T> f;

public:
    constexpr Shape() = delete;
    constexpr explicit Shape(const VoidFunctionType<T>& functionType) : f{functionType} {};
    ~Shape() = default;

    virtual constexpr void rotate(const T& value) const { f(value); }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP
