//
// Created by Michael Lewis on 6/8/23.
//

#include "Circle.hpp"
#include "Monitor.hpp"
#include "MonitorBuilder.hpp"

/**
 * Construct a concrete CAD object specialized for Televisions
 */
ShapePointer MonitorBuilder::getShape()
{
    return std::make_shared<Circle>(Circle());
}

/**
 * Construct a concrete IO device
 */
IODevicePointer MonitorBuilder::getIODevice()
{
    return std::make_shared<Monitor>(Monitor());
}
