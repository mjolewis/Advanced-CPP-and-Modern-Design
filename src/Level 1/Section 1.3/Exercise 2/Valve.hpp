//
// Created by Michael Lewis on 6/2/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_VALVE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_VALVE_HPP

#include <iostream>

class Valve
{
public:
    constexpr Valve() = default;
    ~Valve() = default;

    void rotate(double d) const {std::cout << "Valve" << std::endl;}
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_VALVE_HPP
