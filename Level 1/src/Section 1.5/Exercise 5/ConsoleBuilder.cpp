//
// Created by Michael Lewis on 6/10/23.
//

#include <memory>

#include "Console.hpp"
#include "ConsoleBuilder.hpp"

/**
 * Construct a concrete CAD object specialized for Televisions
 */
ShapePointer ConsoleBuilder::getShape()
{
    return std::make_shared<Line>(Line());
}

/**
 * Construct a concrete IO Device
 */
IODevicePointer ConsoleBuilder::getIODevice()
{
    return std::make_shared<Console>(Console());
}
