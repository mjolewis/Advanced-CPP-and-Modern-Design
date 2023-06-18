//
// Created by Michael Lewis on 6/8/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_MONITOR_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_MONITOR_HPP

#include <iostream>

#include "IODevice.hpp"
#include "Circle.hpp"
#include "Line.hpp"

/**
 * A concrete IO device
 */
class Monitor : public IODevice
{
public:
    constexpr Monitor() = default;
    Monitor(const Monitor& source) = delete; // deleted only for simplicity. Example will be expanded in later exercises
    Monitor(Monitor&& source) = default; // move ctor is required when using shared pointers
    virtual ~Monitor() = default;

    // Operator overloads
    Monitor& operator=(const Monitor& source) = delete; // deleted only for simplicity. Example will be expanded in later exercises
    Monitor& operator=(Monitor&& source) = delete; // deleted only for simplicity. Example will be expanded in later exercises

    // Base class overrides
    void operator << (const Circle& circle) override;
    void operator << (const Line& line) override;
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_MONITOR_HPP
