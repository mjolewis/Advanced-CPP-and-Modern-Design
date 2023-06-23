//
// Simple test class to illustrate functionality of shared_ptr
//
// Created by Michael Lewis on 6/22/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_C2_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_C2_HPP

#include <iostream>
#include <memory>
#include <utility>

#include "Point.hpp"

class C2
{
private:
    //double* d; OLD WAY
    std::shared_ptr<double> d;
    std::shared_ptr<Point> p;
public:
    C2(std::shared_ptr<double> value) : d(std::move(value)) {}  // Move should generally be used when passing by value.
    C2(std::shared_ptr<Point> value) : p(std::move(value)) {}  // Move should generally be used when passing by value.
    virtual ~C2() { std::cout <<"\nC1 destructor\n";} // Move should generally be used when passing by value.
    void print() const { std::cout <<"Value "<<* d; }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_C2_HPP
