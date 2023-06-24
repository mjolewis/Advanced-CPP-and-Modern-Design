//
// A simple derived class to illustrate the use of smart pointers with STL algorithms
//
// Created by Michael Lewis on 6/23/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_DERIVED_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_DERIVED_HPP

#include <iostream>

#include "Base.hpp"

// Derived class
class Derived : public Base
{
private:
public:
    Derived() : Base() { }
    ~Derived() override { std::cout << "Derived destructor\n"; }
    void print() const override { std::cout << "derived object\n";}
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_DERIVED_HPP
