//
// Created by Michael Lewis on 6/8/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_BUILDER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_BUILDER_HPP

#include <memory>

#include "IODevice.hpp"
#include "Circle.hpp"
#include "Monitor.hpp"
#include "Shape.hpp"

using ShapePointer = std::shared_ptr<Shape>;
using IODevicePointer = std::shared_ptr<IODevice>;

/**
 * A Builder hierarchy that builds shapes and IO devices
 *
 * Implemented using a simplistic Builder pattern from GOF
 */
class Builder
{
public:
    constexpr Builder() = default;
    virtual ~Builder() = default;

    std::tuple<ShapePointer, IODevicePointer> getProduct()
    {
        return std::make_tuple(getShape(), getIODevice());
    }

    // Hook functions that derived classes must implement
    virtual ShapePointer getShape() = 0;
    virtual IODevicePointer getIODevice() = 0;
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_BUILDER_HPP
