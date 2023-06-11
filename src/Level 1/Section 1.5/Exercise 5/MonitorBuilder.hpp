//
// Created by Michael Lewis on 6/8/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_MONITORBUILDER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_MONITORBUILDER_HPP

#include "Builder.hpp"
#include "IODevice.hpp"
#include "Shape.hpp"

/**
 * Builds a monitor as an IODevice
 */
class MonitorBuilder : public Builder
{
public:
    constexpr MonitorBuilder() = default;
    MonitorBuilder(const Builder& builder) = delete;  // deleted only for simplicity. Example will be expanded in later exercises
    MonitorBuilder(Builder&& builder) = delete; // deleted only for simplicity. Example will be expanded in later exercises
    ~MonitorBuilder() = default;

    // Operator overload
    MonitorBuilder& operator=(const MonitorBuilder& builder) = delete; // deleted only for simplicity. Example will be expanded in later exercises
    MonitorBuilder& operator=(MonitorBuilder&& builder) noexcept = delete; // deleted only for simplicity. Example will be expanded in later exercises

    ShapePointer getShape() override;
    IODevicePointer getIODevice() override;
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_MONITORBUILDER_HPP
