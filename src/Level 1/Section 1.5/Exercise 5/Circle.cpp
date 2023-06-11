//
// Created by Michael Lewis on 6/9/23.
//

#include <iostream>
#include <sstream>

#include "Circle.hpp"
#include "IODevice.hpp"

/**
 * Displays the current object onto the given IODevice
 */
void Circle::display(IODevice& ioDevice) const
{
    ioDevice << *this;
}
