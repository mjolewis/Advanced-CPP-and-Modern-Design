//
// Unlike the Observer Pattern, the Propagator Pattern allows for standalone observer classes.
// LongFormat is one such standalone observer.
//
// Created by Michael Lewis on 8/16/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_LONGFORMAT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_LONGFORMAT_HPP

#include "Propagator.hpp"

class LongFormat
{
public:
    LongFormat() = default;
    LongFormat(const LongFormat& other) = default;
    LongFormat(LongFormat&& other) = default;
    ~LongFormat() = default;

    // Operator Overloads
    LongFormat& operator=(const LongFormat& other) = default;
    LongFormat& operator=(LongFormat&& other) = default;
    void operator()(const Propagator &observable) const;

    void update(const Propagator &observable) const;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_LONGFORMAT_HPP
