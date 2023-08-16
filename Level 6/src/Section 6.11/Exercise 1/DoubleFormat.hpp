//
// Concrete Observer that will print the value of the Subjects counter in double format
//
// Created by Michael Lewis on 8/16/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_DOUBLEFORMAT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_DOUBLEFORMAT_HPP

#include "Observer.hpp"

class DoubleFormat : public Observer
{
public:
    DoubleFormat() = default;
    DoubleFormat(const DoubleFormat& other) = default;
    DoubleFormat(DoubleFormat&& other) = default;
    ~DoubleFormat() override = default;

    // Operator Overloads
    DoubleFormat& operator=(const DoubleFormat& other) = default;
    DoubleFormat& operator=(DoubleFormat&& other) = default;

    void update(const Subject& subject);
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_DOUBLEFORMAT_HPP
