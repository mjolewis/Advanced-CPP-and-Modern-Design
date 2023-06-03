//
// Created by Michael Lewis on 6/2/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CIRCLE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CIRCLE_HPP

#include <iostream>
#include <functional>

#include "Shape.hpp"

/**
 * A derived class of Shape that illustrates how to emulate
 * polymorphism using function wrappers.
 *
 * Improves performance by eliminating virtual function calls
 */
template<typename T>
class Circle : Shape<T>
{
public:
    constexpr Circle() = delete;
    constexpr explicit Circle(const VoidFunctionType<T>& functionType) : Shape<T>{functionType} {};
    ~Circle() = default;

    constexpr void rotate(const T& value) const override { Shape<T>::f(value); }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_CIRCLE_HPP
