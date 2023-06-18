//
// Created by Michael Lewis on 6/10/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CONSOLEBUILDER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CONSOLEBUILDER_HPP

#include "Builder.hpp"

/**
 * A concrete builder responsible for constructing a Console as an IODevice
 */
class ConsoleBuilder : public Builder
{
public:
    constexpr ConsoleBuilder() = default;
    ConsoleBuilder(const ConsoleBuilder& source) = delete; // deleted only for simplicity. Example will be expanded in later exercises
    ConsoleBuilder(ConsoleBuilder&& source) = delete; // deleted only for simplicity. Example will be expanded in later exercises
    virtual ~ConsoleBuilder() = default;

    // Overloaded operators
    ConsoleBuilder& operator=(const ConsoleBuilder& source) = delete; // deleted only for simplicity. Example will be expanded in later exercises
    ConsoleBuilder& operator=(const ConsoleBuilder&& source) = delete; // deleted only for simplicity. Example will be expanded in later exercises

    // Base class overrides
    ShapePointer getShape() override;
    IODevicePointer getIODevice() override;
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_CONSOLEBUILDER_HPP
