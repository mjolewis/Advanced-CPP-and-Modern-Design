//
// Created by Michael Lewis on 6/8/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CONSOLE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CONSOLE_HPP

#include "IODevice.hpp"
#include "Line.hpp"

/**
 * A concrete IO device
 */
class Console : public IODevice
{
public:
    constexpr Console() = default;
    Console(const Console& source) = delete; // deleted only for simplicity. Example will be expanded in later exercises
    Console(Console&& source) = default; // move ctor is required when using shared pointers
    virtual ~Console() = default;

    // Operator overload
    Console& operator=(const Console& source) = delete; // deleted only for simplicity. Example will be expanded in later exercises
    Console& operator=(Console&& source) = delete; // deleted only for simplicity. Example will be expanded in later exercises

    // Base class overrides
    void operator << (const Circle& circle) override;
    void operator << (const Line& line) override;
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_CONSOLE_HPP
