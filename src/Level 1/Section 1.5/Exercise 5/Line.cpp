//
// Created by Michael Lewis on 6/9/23.
//

#include "Line.hpp"

/**
 * Displays the current object onto the given IODevice
 */
void Line::display(IODevice &ioDevice) const
{
    ioDevice << *this;
}
