//
// Simple test class to illustrate functionality of shared_ptr
//
// Created by Michael Lewis on 6/22/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_C1_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_C1_HPP

#include <memory>
#include <iostream>
#include <utility>

#include "Point.hpp"

class C1
{
private:
    //double* d; OLD WAY
    std::shared_ptr<double> d;
    std::shared_ptr<Point> p;
public:
    C1(std::shared_ptr<double> value) : d(std::move(value)) {} // Move should generally be used when passing by value.
    C1(std::shared_ptr<Point> value) : p(std::move(value)) {} // Move should generally be used when passing by value.
    virtual ~C1() { std::cout <<"\nC1 destructor\n";}
    void print() const { std::cout <<"Value "<< *d; }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_C1_HPP
