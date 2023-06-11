//
// Created by Michael Lewis on 6/10/23.
//

#include <iostream>

#include "Circle.hpp"
#include "Line.hpp"
#include "Console.hpp"

/**
 * Prints to console for now. Can be extended for more robust behavior in displaying a line
 */
void Console::operator<<(const Line& line)
{
    std::cout << "Console + Line" << std::endl;
}

/**
 * Prints to console for now. Can be extended for more robust behavior in displaying a circle
 */
void Console::operator<<(const Circle& circle)
{
    std::cout << "Console + Circle" << std::endl;
}