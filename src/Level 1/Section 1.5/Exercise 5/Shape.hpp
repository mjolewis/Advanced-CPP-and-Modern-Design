//
// Created by Michael Lewis on 6/8/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP

// Forward declaration
//class IODevice;

#include "IODevice.hpp"

/**
 * An abstract interface for concrete CAD objects
 */
class Shape
{
public:
    virtual ~Shape() = default;

    virtual void display(IODevice& ioDevice) const = 0;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP
