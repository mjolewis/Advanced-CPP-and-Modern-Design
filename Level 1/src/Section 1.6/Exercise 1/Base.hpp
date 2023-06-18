//
// Created by Michael Lewis on 6/11/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_BASE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_BASE_HPP

#include "iostream"

struct Base
{
    virtual void draw() { std::cout << "print a base\n"; }
    virtual void print() {}
    ~Base() { std::cout << "bye base\n"; }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_BASE_HPP
