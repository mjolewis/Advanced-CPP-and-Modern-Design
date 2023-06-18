//
// Created by Michael Lewis on 6/10/23.
//

#include <sstream>

#include "Circle.hpp"
#include "Line.hpp"
#include "Monitor.hpp"

/**
 * Prints to console for now. Can be extended for more robust behavior in displaying a line
 */
void Monitor::operator<<(const Line& line)
{
    std::cout << "Monitor + Line" << std::endl;
}

/**
 * Prints to console for now. Can be extended for more robust behavior in displaying a circle
 */
void Monitor::operator<<(const Circle& circle)
{
    std::cout << "Monitor + Circle" << std::endl;
}
