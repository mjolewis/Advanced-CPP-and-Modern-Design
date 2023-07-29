//
// Simple Struct to illustrate how to use function objects with signals and slots
//
// Created by Michael Lewis on 7/29/23.
//

#include <iostream>

#include "MyStruct.hpp"

/**
 * Overloaded ctor
 * @param v Initial value of this Struct
 */
MyStruct::MyStruct(double v) : val{v}
{

}

/**
 * Modifies the value contained in this structure
 * @param newValue The new value of the Struct member
 */
void MyStruct::modify(double newValue)
{
    val = newValue;
    std::cout << "A third slot " << val << std::endl;
}