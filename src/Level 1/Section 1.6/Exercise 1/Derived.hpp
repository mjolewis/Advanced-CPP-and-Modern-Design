//
// Created by Michael Lewis on 6/11/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_DERIVED_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_DERIVED_HPP

#include <iostream>

#include "Base.hpp"

struct Derived : public Base
{
    Derived() = default;
    void draw() override { std::cout << "print a derived\n"; }
    void draw() const {}
    void print() override {}
    ~Derived() { std::cout << "bye derived\n"; }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_DERIVED_HPP
