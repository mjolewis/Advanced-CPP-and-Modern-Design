//
// Concrete Observer that will print the value of the Subjects counter in long format
//
// Created by Michael Lewis on 8/16/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_LONGFORMAT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_LONGFORMAT_HPP

#include "Observer.hpp"
#include "Subject.hpp"

class LongFormat : public Observer
{
public:
    LongFormat() = default;
    LongFormat(const LongFormat& other) = default;
    LongFormat(LongFormat&& other) = default;
    ~LongFormat() override = default;

    // Operator Overloads
    LongFormat& operator=(const LongFormat& other) = default;
    LongFormat& operator=(LongFormat&& other) = default;

    void update(const Subject& subject);
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_LONGFORMAT_HPP
