//
// A simple bvase class to illustrate the use of smart pointers with STL algorithms
//
// Created by Michael Lewis on 6/23/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_BASE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_BASE_HPP

#include <iostream>

// Base class
class Base
{
private:
protected:
    virtual ~Base() { std::cout << "Base destructor\n\n"; }
public:
    Base() { }
    virtual void print() const = 0;
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_BASE_HPP
